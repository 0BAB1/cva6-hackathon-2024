#include <stdint.h>
#include "uart.h"
  
int main(void)
{
        char a = -10;
        char* a_addr = &a;

        for(char i = 0; i < 150; i++){
                asm volatile("lbc x0 0(%0)"
                : 
                : "r" (a_addr)
                );
                asm volatile("lbcu x0 0(%0)"
                : 
                : "r" (a_addr)
                );
                asm volatile("lb x0 0(%0)"
                : 
                : "r" (a_addr)
                );
                asm volatile("lbu x0 0(%0)"
                : 
                : "r" (a_addr)
                );
        }

        uint8_t message[12] = "Hello World";
        UART_init(&g_uart_0,
                UART_115200_BAUD,
                UART_DATA_8_BITS | UART_NO_PARITY | UART_ONE_STOP_BIT);
                        
        UART_polled_tx_string(&g_uart_0, message);

        while(UART_tx_complete(&g_uart_0)==0);
        
        return(0);
}
