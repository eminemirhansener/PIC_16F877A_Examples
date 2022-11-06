	    list	    p=16F877A ;Microcontroller is introduced.
	    include	    "P16F877A.INC" ;Microcontroller library
	    __CONFIG	    _CP_OFF& _DEBUG_OFF& _WRT_OFF& _CPD_OFF& _LVP_OFF& _BODEN_OFF& _PWRTE_ON& _WDT_OFF& _XT_OSC ;Required configurations are set up.
	    org		    0x00 ;Program starts executing from reset vector(starting adress).
	    bsf		    0x03, 5 ;Switch to BANK1
	    movlw	    b'00001100' ;The value assigned to the w.
	    movwf	    0x06 ;The value which was assigned to w is pointed to TRISB to decide I/O pins.
	    bcf		    0x03, 5 ;Switch to BANK0.
	    
test1
    btfsc 0x06, 2 ;Skip 'led1on' if PORTB's 2th bit is clear.
    goto led1on
    goto led1off

test2
    btfss 0x06, 3 ;Skip 'led2off' if PORTB's 3th bit is set.
    goto led2on
    goto led2off
    
;********************************
    
;LED connected to PORTB's 0th bit.
led1on
    bsf 0x06, 0 ;LED on
    goto test2
    
led1off
    bcf 0x06, 0 ;LED off
    goto test2
    
;********************************
    
;LED connected to PORTB's 1th bit
led2on
    bsf 0x06, 1 ;LED on
    goto test1
    
led2off
    bcf 0x06, 1 ;LED off
    goto test1
    
    end
