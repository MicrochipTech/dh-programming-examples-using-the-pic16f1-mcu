/*
 * Programming a Single Interrupt on the Enhanced Mid-Rage MCU
 * Author: David Stokes
 *
 *  For use with Developer Help's "Geting Started with the PIC16F1xxx MCU" Tutorial
 *  Created  September 8,  2014
 *
 /*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

//Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

#include "configs.h"           // configuration bits
#include <xc.h>                   // MPLAB XC8 header file

void initialize_tmr2(void)
{
    TMR2ON = 1;
    T2CONbits.T2CKPS = 3 ;         // set pre-scaler to 64
    T2CONbits.T2OUTPS1 = 1 ;     // post scaler = 3
     PR2 = 255;
}

void interrupt ISR(void)
{
    TMR2IF = 0 ;                               // clear interrupt flag
    LATE ^= 0x03;                           //  Toggle  RE1 and RE0
}

int main(void)
{
    LATE = 0x01 ;                             // Set RE0 = 1 and RE1 = 0
    TRISE = 0xFC;                            // set RE0 and RE1 as outputs
    initialize_tmr2();

    TMR2IE = 1;                                // enable Timer2 interrupt
    PEIE = 1;                                     // enable peripheral interrupts
    GIE = 1 ;                                      // enable global interrupts

    while(1);
}

