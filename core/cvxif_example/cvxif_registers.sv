// By Hugo BABIN-RIBY for CVA6 2023 hackathon
// Desc : cvxif non-addressed registers

module cvxif_registers #(
    parameter Nb_of_regs,
    parameter signed_regs = 0,
    parameter reg_width = 9
) (
    // CVA6 base signals
    input logic clk_i,
    input logic rst_ni,
    // Dump signal, equivalent to reset, set all to 0
    input logic dump_i,
    // WriteEnable signal
    input logic we_i,
    // actual data to load
    input logic [reg_width-1:0] wb_data_i,
    // register memory
    output logic [Nb_of_regs-1:0][reg_width-1:0] regs_q,
    // output pointer to check when loading is finished
    output logic [reg_width-1:0] wb_pointer_q
);

logic [reg_width-1:0] wb_pointer_q; // todo : fix this, supposed to be log_2(150)

// overflowing ?
logic overflow;
assign overflow = (wb_pointer_q >= Nb_of_regs);

if(signed_regs) begin
    logic signed   [Nb_of_regs-1:0][reg_width-1:0] regs_q;
end else begin
    logic unsigned [Nb_of_regs-1:0][reg_width-1:0] regs_q;
end

integer i;
always_ff @(posedge clk_i) begin
    //hadle reset signals (nrst_i & dump_i)
    if (~rst_ni || dump_i) begin
        for (i = 0; i < Nb_of_regs; i++) begin : reset_cvxif_regs
            regs_q[i] <= 9'b0;
        end
        wb_pointer_q <= 0;
    end
    if(we_i) begin
        regs_q[wb_pointer_q] <= wb_data_i;
        wb_pointer_q <= wb_pointer_q + 1;
    end 
end
    
endmodule