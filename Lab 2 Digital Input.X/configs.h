
// PIC16F1937 Configuration Bit Settings

#include <xc.h>

// CONFIG1
#pragma config FOSC = INTOSC      // INTOSC oscillator
#pragma config WDTE = OFF            // WDT disabled
#pragma config PWRTE = OFF         // Power-up Timer disabled
#pragma config MCLRE = ON           // MCLR/VPP pin function is MCLR
#pragma config CP = OFF                 // Code protection is disabled
#pragma config CPD = OFF              //  Data Memory Code Protection disabled
#pragma config BOREN = OFF         // Brown-out Reset disabled
#pragma config CLKOUTEN = OFF  // Clock Out  disabled. 
#pragma config IESO = OFF             // Internal/External Switchover disabled
#pragma config FCMEN = OFF         // Fail-Safe Clock Monitor is disabled

// CONFIG2
#pragma config WRT = OFF            // Flash Memory Self-Write Protection off
#pragma config PLLEN = ON          // PLL Enable (4x PLL enabled)
#pragma config STVREN = OFF     // Stack Overflow /Underflow reset disabled
#pragma config BORV = LO           // Brown-out Reset Voltage Selection
#pragma config LVP = OFF            // Low-Voltage Programming disbled


