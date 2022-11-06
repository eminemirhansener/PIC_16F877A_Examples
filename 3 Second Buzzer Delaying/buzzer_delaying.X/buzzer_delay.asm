	    list	    p=16F877A ;Microcontroller is introduced.
	    include	    "P16F877A.INC" ;Microcontroller library
	    __CONFIG	    _CP_OFF& _DEBUG_OFF& _WRT_OFF& _CPD_OFF& _LVP_OFF& _BODEN_OFF& _PWRTE_OFF& _WDT_OFF& _XT_OSC ;Required configurations are set up.
	    org		    0x00 ;Program starts executing from reset vector(starting adress).
	    bsf		    0x03, 5 ;Switch to BANK1
	    movlw	    b'00000001' ;The value assigned to the w.
	    movwf	    0x06 ;The value which was assigned to w is pointed to TRISD to decide I/O pins.
	    bcf		    0x03, 5 ;Switch to BANK0.
	    clrf	    0x06
	    
main
	    btfss	    0x06, 0
	    goto	    main
	    goto	    buzzer
	    
buzzer
	    bsf		    0x06, 1
	    call	    delay_3_sec
	    bcf		    0x06, 1
	    call	    delay_3_sec
	    btfsc	    0x06, 0
	    goto	    buzzer
	    goto	    main
	    
	    
delay_one_ms
	    movlw	    d'250'
	    movwf	    0x20
	    
loop_one_ms
	    nop
	    decfsz	    0x20, f
	    goto	    loop_one_ms
	    return
	    
	    
delay_250_ms
	    movlw	    d'250'
	    movwf	    0x21
	    
loop_250_ms
	    call	    delay_one_ms
	    decfsz	    0x21, f
	    goto	    loop_250_ms
	    return
	    
	    
delay_3_sec
	    movlw	    d'12'
	    movwf	    0x22
	    
loop_3_sec
	    call	    delay_250_ms
	    decfsz	    0x22, f
	    goto	    loop_3_sec
	    return
	    
	    
end
	    


