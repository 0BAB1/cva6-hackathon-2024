// Copyright 2021 Thales DIS design services SAS
//
// Licensed under the Solderpad Hardware Licence, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.0
// You may obtain a copy of the License at https://solderpad.org/licenses/
//
// Original Author: Guillaume Chauvon (guillaume.chauvon@thalesgroup.com)
// Example coprocessor adds rs1,rs2(,rs3) together and gives back the result to the CPU via the CoreV-X-Interface.
// Coprocessor delays the sending of the result depending on result least significant bits.

module cvxif_example_coprocessor
  import cvxif_pkg::*;
  import cvxif_instr_pkg::*;
  import ariane_pkg::*;
(
    input  logic                clk_i,        // Clock
    input  logic                rst_ni,       // Asynchronous reset active low
    input  cvxif_req_t          cvxif_req_i,
    output cvxif_resp_t         cvxif_resp_o,
    input  logic                commit_ack_i, // commit_ack from commit stage
    input  scoreboard_entry_t   commit_sbe_i  // from scoreboard 
);

  localparam Nb_of_regs = 151 ;
  // =================================
  // hugo modif : REGISTERS INTERFACE
  // =================================

  logic [Nb_of_regs-1:0][8:0] inputs;
  logic signed   [Nb_of_regs-1:0][8:0] weights;
  // reg wb pointer tocheck loading finished ot not. by convention
  // in software, weights are loaded after so we get it from here
  logic [7:0] reg_wb_pointer; // todo : fix size of pointer to log
  cvxif_registers #(
    .Nb_of_regs(Nb_of_regs),
    .signed_regs(1)
  ) weights_registers (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    // if we is 1 in result, it means we executed and have to dump regs
    .dump_i(x_result_o.we),
    .we_i(registers_ctrl.we && registers_ctrl.is_weight),
    .wb_data_i({registers_ctrl.data[7] , registers_ctrl.data}),
    .regs_q(weights),
    .wb_pointer_q(reg_wb_pointer)
  );

  cvxif_registers #(
    .Nb_of_regs(Nb_of_regs),
    .signed_regs(0)
  ) inputs_registers (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    // if we is 1 in result, it means we executed and have to dump regs
    .dump_i(x_result_o.we),
    .we_i(registers_ctrl.we && ~registers_ctrl.is_weight),
    // ALWAYS unsigned so we sign extend on the 9th bit with 0
    .wb_data_i({1'b0,registers_ctrl.data}),
    .regs_q(inputs)
  );

  // ============================================
  // hugo modif : EXTRACT DATA FROM COMMIT INSTR.
  // ============================================

  // added a type, because why not ?
  typedef struct packed{
    logic       we;
    logic       is_weight; //if =1 the store in weights register and if =0, then store in inputs regs (16 each)
    logic [7:0] data;
  } destination_register_t;

  // this store the onfos needed to manage the register interface
  destination_register_t registers_ctrl;
  
  always_comb begin : cvxif_commit
    registers_ctrl.we = 1'b0;
    registers_ctrl.is_weight = 0;
    registers_ctrl.data = 0;
    // commit if commit stage says its OK
    if (commit_ack_i) begin
      if(commit_sbe_i.op == LBC || commit_sbe_i.op == LBCU) begin
        registers_ctrl.we = 1'b1;
        // observation : LBC is used for weigths & LBCU is used for inputs !
        registers_ctrl.is_weight = (commit_sbe_i.op == LBC) ? 1 : 0 ;
        registers_ctrl.data = commit_sbe_i.result[7:0];
      end 
    end
  end

  // ======================================
  // hugo modif : COMPUTE RESULT IN PRRALEL
  // ======================================

  // note : pipeline result tp respect timings !
  logic signed [Nb_of_regs-1:0][17:0] mult_results_n, mult_results_q; 
  logic signed [31:0] end_result;

  integer i;
  always_comb begin : compute_result
    for(i=0;i<Nb_of_regs;i++) begin
      mult_results_n[i] = signed'(inputs[i]) * signed'(weights[i]);
    end
  end

  // compute result as a sum
  integer j;
  always_comb begin
  end_result = 0;
    for (integer j = 0; j < Nb_of_regs; j++) begin
        end_result = signed'(end_result) + signed'(mult_results_q[j]);
    end
  end


  //Compressed interface
  logic               x_compressed_valid_i;
  logic               x_compressed_ready_o;
  x_compressed_req_t  x_compressed_req_i;
  x_compressed_resp_t x_compressed_resp_o;
  //Issue interface
  logic               x_issue_valid_i;
  logic               x_issue_ready_o;
  x_issue_req_t       x_issue_req_i;
  x_issue_resp_t      x_issue_resp_o;
  //Commit interface
  logic               x_commit_valid_i;
  x_commit_t          x_commit_i;
  //Memory interface
  logic               x_mem_valid_o;
  logic               x_mem_ready_i;
  x_mem_req_t         x_mem_req_o;
  x_mem_resp_t        x_mem_resp_i;
  //Memory result interface
  logic               x_mem_result_valid_i;
  x_mem_result_t      x_mem_result_i;
  //Result interface
  logic               x_result_valid_o;
  logic               x_result_ready_i;
  x_result_t          x_result_o;

  assign x_compressed_valid_i            = cvxif_req_i.x_compressed_valid;
  assign x_compressed_req_i              = cvxif_req_i.x_compressed_req;
  assign x_issue_valid_i                 = cvxif_req_i.x_issue_valid;
  assign x_issue_req_i                   = cvxif_req_i.x_issue_req;
  assign x_commit_valid_i                = cvxif_req_i.x_commit_valid;
  assign x_commit_i                      = cvxif_req_i.x_commit;
  assign x_mem_ready_i                   = cvxif_req_i.x_mem_ready;
  assign x_mem_resp_i                    = cvxif_req_i.x_mem_resp;
  assign x_mem_result_valid_i            = cvxif_req_i.x_mem_result_valid;
  assign x_mem_result_i                  = cvxif_req_i.x_mem_result;
  assign x_result_ready_i                = cvxif_req_i.x_result_ready;

  assign cvxif_resp_o.x_compressed_ready = x_compressed_ready_o;
  assign cvxif_resp_o.x_compressed_resp  = x_compressed_resp_o;
  assign cvxif_resp_o.x_issue_ready      = x_issue_ready_o;
  assign cvxif_resp_o.x_issue_resp       = x_issue_resp_o;
  assign cvxif_resp_o.x_mem_valid        = x_mem_valid_o;
  assign cvxif_resp_o.x_mem_req          = x_mem_req_o;
  assign cvxif_resp_o.x_result_valid     = x_result_valid_o;
  assign cvxif_resp_o.x_result           = x_result_o;

  //Compressed interface
  assign x_compressed_ready_o            = '0;
  assign x_compressed_resp_o.instr       = '0;
  assign x_compressed_resp_o.accept      = '0;

  instr_decoder #(
      .NbInstr   (cvxif_instr_pkg::NbInstr),
      .CoproInstr(cvxif_instr_pkg::CoproInstr)
  ) instr_decoder_i (
      .clk_i         (clk_i),
      .x_issue_req_i (x_issue_req_i),
      .x_issue_resp_o(x_issue_resp_o)
  );

  typedef struct packed {
    x_issue_req_t  req;
    x_issue_resp_t resp;
  } x_issue_t;

  logic fifo_full, fifo_empty;
  logic x_issue_ready_q;
  logic instr_push, instr_pop;
  x_issue_t req_i;
  x_issue_t req_o;

  assign instr_push = x_issue_resp_o.accept ? 1 : 0;
  assign instr_pop = (x_commit_i.x_commit_kill && x_commit_valid_i) || x_result_valid_o;
  assign x_issue_ready_q = ~fifo_full; // if something is in the fifo, the instruction is being processed
                                       // so we can't receive anything else
  assign req_i.req = x_issue_req_i;
  assign req_i.resp = x_issue_resp_o;

  // check wether load is over 
  logic load_finish_n, load_finish_q;
  assign load_finish_n = reg_wb_pointer == (req_o.req.rs[1]);

  always_ff @(posedge clk_i or negedge rst_ni) begin : regs
    if (!rst_ni) begin
      x_issue_ready_o <= 1;
      mult_results_q <= 0;
      load_finish_q <= 0;
    end else begin
      x_issue_ready_o <= x_issue_ready_q;
      mult_results_q <= mult_results_n;
      load_finish_q <= load_finish_n;
    end
  end

  fifo_v3 #(
      .FALL_THROUGH(1),         //data_o ready and pop in the same cycle
      .DATA_WIDTH  (64),
      .DEPTH       (8),
      .dtype       (x_issue_t)
  ) fifo_commit_i (
      .clk_i     (clk_i),
      .rst_ni    (rst_ni),
      .flush_i   (1'b0),
      .testmode_i(1'b0),
      .full_o    (fifo_full),
      .empty_o   (fifo_empty),
      .usage_o   (),
      .data_i    (req_i),
      .push_i    (instr_push),
      .data_o    (req_o),
      .pop_i     (instr_pop)
  );

  // Assemble result for response
  always_comb begin
    x_result_o.data    = signed'(end_result + req_o.req.rs[0]);
    // note : use RS2 (nb of total iterations) to see if all hav been loaded correctly !
    x_result_valid_o   = ~fifo_empty && (load_finish_q);
    x_result_o.id      = req_o.req.id;
    x_result_o.rd      = req_o.req.instr[11:7];
    x_result_o.we      = req_o.resp.writeback & x_result_valid_o;
    x_result_o.exc     = 0;
    x_result_o.exccode = 0;
  end

endmodule
