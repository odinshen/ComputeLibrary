//------------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//            (C) COPYRIGHT 2013-2016 ARM Limited or its affiliates.
//                ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//
//            Release Information : CORINTH-MP090-dev-20160525
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Purpose:
//   Output a character to the tube
//------------------------------------------------------------------------------

// void output_char(char c)
// {
//     volatile char *tube = (volatile char *) 0x13000000u;
//
//     *tube = c;
// }
#include "uart.h"
#include "intgrt.h"

void init_serial_A(void)
{
  /* Disable the serial port while setting the baud rate and word length */
  UART0_CR = 0;

  /* Setting the correct baud rate and word length */
  UART0_LCRL = LCRL_Baud_460800;      // LCRL and LCRM writes _MUST_
                                      // be performed before the LCRH
  UART0_LCRM = LCRM_Baud_460800;      // write as LCRH generates the
                                      // write strobe to transfer the
  UART0_LCRH = LCRH_Word_Length_8;    // data. FIFO disabled.

  /* Now enable the serial port */
  UART0_CR   = CR_UART_Enable | CR_TX_Int_Enable | CR_RX_Int_Enable;        // Enable UART0 with no interrupts
}

void output_char(unsigned char ch)
{
  while (UART0_FR & FR_TX_Fifo_Full)
    ;
  UART0_DR = ch;                     // Transmit next character
}
