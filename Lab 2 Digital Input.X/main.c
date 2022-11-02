/*
 * Programming a  Digital Input on the Enhanced Mid-Rage MCU
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

int main(void)
{
    TRISEbits.TRISE2 = 0 ;         // make RE2 an output pin
    ANSELDbits.ANSD2 = 0;      // make RD2 an analog pin
    TRISD = 0xFF;                       // ensure all PORTD pins are inputs
    while(1)
    {
        LATEbits.LATE2 = PORTDbits.RD2 ;
    }
}



