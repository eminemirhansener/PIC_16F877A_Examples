#include <16F877A.h>
#include <stdlib.h>
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay(CLOCK = 4M)
#define use_portb_lcd TRUE

#use rs232 (baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N, stop=1)

#include <lcd.c>

char inp[6];
int P;
int I;
int D;

int counter = 0;

void main()
{
      set_tris_b(0x00);
      set_tris_c(0b10000000);
      lcd_init();
      delay_ms(10);
      
      while(1)
      {
            if(kbhit())
            {
                  char i = getc();
                  
                  if(i != 'P' && i != 'I' && i != 'D')
                  {
                        inp[counter] = i;
                        counter++;
                  }
                  
                  if(i == 'D')
                  {
                  
                        counter = 0;
                        P = (((int)(inp[0])-48)*10) + ((int)(inp[1])-48);
                        I = (((int)(inp[2])-48)*10) + ((int)(inp[3])-48);
                        D = (((int)(inp[4])-48)*10) + ((int)(inp[5])-48);
                        
                        lcd_gotoxy(1,1);
                        printf(lcd_putc, "\fKp: %d, Ki: %d\nKd: %d", P, I, D);

                        memset(inp, 0, 6);
                        
                        delay_ms(2000);
                        
                  }
            }
      }
}
