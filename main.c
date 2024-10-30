#include <stdint.h>
#include "tm4c123gh6pm.h"


void UART0_Init(void);
char UART0_Received(void);
void UART0_Send(char data);
void LED_Init(void);
void LED_ON_OFF(char choice);

int main(void) {

    }
}
void LED_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x20;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;
}
void UART0_Init(void) {
 SYSCTL_RCGCUART_R |= 0x01;
        SYSCTL_RCGCGPIO_R |= 0x01;          // Enable PORTA

        UART0_CTL_R &= ~0x01;               // Disable UART0
        UART0_IBRD_R = 104;                 // Set integer part for baud rate (assuming 16 MHz and 9600 baud)
        UART0_FBRD_R = 11;                  // Set fractional part for baud rate
        UART0_LCRH_R = 0x70;                // 8-bit, no parity, 1-stop bit, FIFOs
        UART0_CTL_R = 0x301;                // Enable UART0, TX, and RX

        GPIO_PORTA_AFSEL_R |= 0x03;         // Enable PA0 and PA1 as alternate function
        GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x11;
        GPIO_PORTA_DEN_R |= 0x03;
}
