/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18877
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TRIMPOT aliases
#define TRIMPOT_TRIS                 TRISAbits.TRISA0
#define TRIMPOT_LAT                  LATAbits.LATA0
#define TRIMPOT_PORT                 PORTAbits.RA0
#define TRIMPOT_WPU                  WPUAbits.WPUA0
#define TRIMPOT_OD                   ODCONAbits.ODCA0
#define TRIMPOT_ANS                  ANSELAbits.ANSA0
#define TRIMPOT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TRIMPOT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TRIMPOT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TRIMPOT_GetValue()           PORTAbits.RA0
#define TRIMPOT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TRIMPOT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TRIMPOT_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TRIMPOT_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TRIMPOT_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define TRIMPOT_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define TRIMPOT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TRIMPOT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set CLIK1CS_N aliases
#define CLIK1CS_N_TRIS                 TRISAbits.TRISA3
#define CLIK1CS_N_LAT                  LATAbits.LATA3
#define CLIK1CS_N_PORT                 PORTAbits.RA3
#define CLIK1CS_N_WPU                  WPUAbits.WPUA3
#define CLIK1CS_N_OD                   ODCONAbits.ODCA3
#define CLIK1CS_N_ANS                  ANSELAbits.ANSA3
#define CLIK1CS_N_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define CLIK1CS_N_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define CLIK1CS_N_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define CLIK1CS_N_GetValue()           PORTAbits.RA3
#define CLIK1CS_N_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define CLIK1CS_N_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define CLIK1CS_N_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define CLIK1CS_N_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define CLIK1CS_N_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define CLIK1CS_N_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define CLIK1CS_N_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define CLIK1CS_N_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA4
#define LED2_LAT                  LATAbits.LATA4
#define LED2_PORT                 PORTAbits.RA4
#define LED2_WPU                  WPUAbits.WPUA4
#define LED2_OD                   ODCONAbits.ODCA4
#define LED2_ANS                  ANSELAbits.ANSA4
#define LED2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED2_GetValue()           PORTAbits.RA4
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA5
#define LED3_LAT                  LATAbits.LATA5
#define LED3_PORT                 PORTAbits.RA5
#define LED3_WPU                  WPUAbits.WPUA5
#define LED3_OD                   ODCONAbits.ODCA5
#define LED3_ANS                  ANSELAbits.ANSA5
#define LED3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED3_GetValue()           PORTAbits.RA5
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISAbits.TRISA6
#define LED4_LAT                  LATAbits.LATA6
#define LED4_PORT                 PORTAbits.RA6
#define LED4_WPU                  WPUAbits.WPUA6
#define LED4_OD                   ODCONAbits.ODCA6
#define LED4_ANS                  ANSELAbits.ANSA6
#define LED4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED4_GetValue()           PORTAbits.RA6
#define LED4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LED4_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS                 TRISAbits.TRISA7
#define LED5_LAT                  LATAbits.LATA7
#define LED5_PORT                 PORTAbits.RA7
#define LED5_WPU                  WPUAbits.WPUA7
#define LED5_OD                   ODCONAbits.ODCA7
#define LED5_ANS                  ANSELAbits.ANSA7
#define LED5_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED5_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED5_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED5_GetValue()           PORTAbits.RA7
#define LED5_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED5_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED5_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED5_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED5_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED5_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define LED5_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set S1PRESS_N aliases
#define S1PRESS_N_TRIS                 TRISBbits.TRISB4
#define S1PRESS_N_LAT                  LATBbits.LATB4
#define S1PRESS_N_PORT                 PORTBbits.RB4
#define S1PRESS_N_WPU                  WPUBbits.WPUB4
#define S1PRESS_N_OD                   ODCONBbits.ODCB4
#define S1PRESS_N_ANS                  ANSELBbits.ANSB4
#define S1PRESS_N_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define S1PRESS_N_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define S1PRESS_N_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define S1PRESS_N_GetValue()           PORTBbits.RB4
#define S1PRESS_N_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define S1PRESS_N_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define S1PRESS_N_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define S1PRESS_N_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define S1PRESS_N_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define S1PRESS_N_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define S1PRESS_N_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define S1PRESS_N_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set S2PRESS_N aliases
#define S2PRESS_N_TRIS                 TRISCbits.TRISC5
#define S2PRESS_N_LAT                  LATCbits.LATC5
#define S2PRESS_N_PORT                 PORTCbits.RC5
#define S2PRESS_N_WPU                  WPUCbits.WPUC5
#define S2PRESS_N_OD                   ODCONCbits.ODCC5
#define S2PRESS_N_ANS                  ANSELCbits.ANSC5
#define S2PRESS_N_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define S2PRESS_N_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define S2PRESS_N_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define S2PRESS_N_GetValue()           PORTCbits.RC5
#define S2PRESS_N_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define S2PRESS_N_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define S2PRESS_N_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define S2PRESS_N_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define S2PRESS_N_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define S2PRESS_N_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define S2PRESS_N_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define S2PRESS_N_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set CLIK2CS_N aliases
#define CLIK2CS_N_TRIS                 TRISDbits.TRISD3
#define CLIK2CS_N_LAT                  LATDbits.LATD3
#define CLIK2CS_N_PORT                 PORTDbits.RD3
#define CLIK2CS_N_WPU                  WPUDbits.WPUD3
#define CLIK2CS_N_OD                   ODCONDbits.ODCD3
#define CLIK2CS_N_ANS                  ANSELDbits.ANSD3
#define CLIK2CS_N_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define CLIK2CS_N_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define CLIK2CS_N_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define CLIK2CS_N_GetValue()           PORTDbits.RD3
#define CLIK2CS_N_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define CLIK2CS_N_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define CLIK2CS_N_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define CLIK2CS_N_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define CLIK2CS_N_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define CLIK2CS_N_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define CLIK2CS_N_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define CLIK2CS_N_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/