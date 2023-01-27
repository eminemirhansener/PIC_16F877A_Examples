#include <16F877A.h>
#include <stdio.h>
#include <stdlib.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4M)
#define use_portb_lcd TRUE

#include <lcd.c>

char keypad_control();

void main()
{
    // Configuring ports and LCD
    setup_psp(PSP_DISABLED);
    setup_timer_1(T1_DISABLED);
    
    setup_adc_ports(NO_ANALOGS);
    setup_adc(ADC_OFF);
    setup_CCP1(CCP_OFF);
    setup_CCP2(CCP_OFF);
    
    set_tris_b(0x00);
    set_tris_d(0b11110000);
    lcd_init();
        
    delay_ms(100);
    
    restart: // To restart operation
    
    int result = 0;
    int num1 = 0;
    int num2 = 0;
    
    char chr[6];
    
    while(keypad_control() != '#' ) //keypad controlled untill '#' is read
    {
         
         keypad_control();
         
    }
    
    // char values are saved into an array
    chr[0] = lcd_getc(1,1);
    delay_ms(10);
    chr[1] = lcd_getc(2,1);
    delay_ms(10);
    chr[2] = lcd_getc(3,1);
    delay_ms(10);
    chr[3] = lcd_getc(4,1);
    delay_ms(10);
    chr[4] = lcd_getc(5,1);
    delay_ms(10);
    chr[5] = lcd_getc(6,1);
    delay_ms(10);
    
    lcd_putc('\f'); //clear screen
    
    lcd_gotoxy(1,1); // reset cursor
    
    // error control
    if(chr[2] != '*' || chr[5] != '#')
    {
         printf(lcd_putc, "SYNTAX ERROR");
         delay_ms(1000);
         lcd_putc('\f');
         goto restart;
    }
    
    //execution
    else
    {
         num1 = 10*((int)(chr[0])-48) + ((int)(chr[1])-48); // 48 is substracted because of ASCII value
         num2 = 10*((int)(chr[3])-48) + ((int)(chr[4])-48);
         result = num1 + num2;
    }
    
    printf(lcd_putc, "%d", result); // Print result
    delay_ms(3000);
    lcd_putc('\f'); // Clear screen
    delay_ms(20);
    
    goto restart;
}


// It is preferred to choose rows as output //
char keypad_control()
{
      
         char input;
         
         output_b(0x00);
        
        //**********************************
        output_high(pin_d0);
        if(input(pin_d4)){delay_ms(100); printf(lcd_putc, "1"); input = '1'; }
        if(input(pin_d5)){delay_ms(100); printf(lcd_putc, "2"); input = '2'; }
        if(input(pin_d6)){delay_ms(100); printf(lcd_putc, "3"); input = '3'; }
        if(input(pin_d7)){delay_ms(100); printf(lcd_putc, "A"); input = 'A'; }
        output_low(pin_d0);
        //**********************************
        
        delay_ms(100);
        
        //**********************************
        
        output_high(pin_d1);
        if(input(pin_d4)){delay_ms(100); printf(lcd_putc, "4"); input = '4'; }
        if(input(pin_d5)){delay_ms(100); printf(lcd_putc, "5"); input = '5'; }
        if(input(pin_d6)){delay_ms(100); printf(lcd_putc, "6"); input = '6'; }
        if(input(pin_d7)){delay_ms(100); printf(lcd_putc, "B"); input = 'B'; }
        output_low(pin_d1);
        //**********************************
        
        delay_ms(100);
        
        //**********************************
        output_high(pin_d2);
        if(input(pin_d4)){delay_ms(100); printf(lcd_putc, "7"); input = '7'; }
        if(input(pin_d5)){delay_ms(100); printf(lcd_putc, "8"); input = '8'; }
        if(input(pin_d6)){delay_ms(100); printf(lcd_putc, "9"); input = '9'; }
        if(input(pin_d7)){delay_ms(100); printf(lcd_putc, "C"); input = 'C'; }
        output_low(pin_d2);
        //**********************************
        
        delay_ms(100);
        
        //**********************************
        output_high(pin_d3);
        if(input(pin_d4)){delay_ms(100); printf(lcd_putc, "*"); input = '*'; }
        if(input(pin_d5)){delay_ms(100); printf(lcd_putc, "0"); input = '0'; }
        if(input(pin_d6)){delay_ms(100); printf(lcd_putc, "#"); input = '#'; }
        if(input(pin_d7)){delay_ms(100); printf(lcd_putc, "D"); input = 'D'; }
        output_low(pin_d3);
        //**********************************
        
        delay_ms(100);
    
      return input;
}

