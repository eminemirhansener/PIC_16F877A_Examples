#include <16F877A.h>
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay(CLOCK = 4M)

#use rs232 (baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N, stop=1)

void main()
{
      while(1)
      
      {
            delay_ms(100);
            printf("2");
            delay_ms(100);
            
            printf("4");
            delay_ms(100);
            
            printf("P");
            delay_ms(100);
            
            printf("6");
            delay_ms(100);
            
            printf("0");
            delay_ms(100);
            
            printf("I");
            delay_ms(100);
            
            printf("6");
            delay_ms(100);
            
            printf("4");
            delay_ms(100);
            
            printf("D");
            delay_ms(100);
      }
}
