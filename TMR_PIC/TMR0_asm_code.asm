;Label Command Operand
list p = 16F877A
#include <p16F877A.INC>
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF ;Configuration Bits Settings
TEMP EQU 0x20 ;General Purpose Register (Counter)
org 0x00 ;Reset Vector
goto MAIN ;Goto MAIN
org 0x04 ;Interrupt Vector
goto TMR0_INT ;Interrupt Service Routine
 
TMR0_INT:
movlw 0x05 ;d'5' 
movwf TMR0 ;0x0C -> TMR0
bcf INTCON,TMR0IF
;Counter
decfsz TEMP,F
RETFIE
movlw .15
movwf TEMP
;-------
movlw H'01' ;B0 -> HIGH
xorwf PORTB,F ;Toggle Port B
RETFIE
    
MAIN:
bsf STATUS,RP0 ;Bank 1
movlw 0x06 ;Close the analog pins for using interrupts
movwf ADCON1 ;ADCON1 address
clrf TRISA ;TRISA -> 0b00000000 (OUTPUT)
clrf TRISB ;TRISB -> 0b00000000 (OUTPUT)
movlw 0x07
movwf OPTION_REG ;Settings -> OPTION_REG
bcf STATUS,RP0 ;Bank0
;Timer settings
movlw 0x05 ;d'5'
movwf TMR0 ;0x0C -> TMR0
;Counter
movlw .15
movwf TEMP

movlw 0xA0
movwf INTCON ;Settings -> INTCON
loop: goto loop ;INF LOOP
end