#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000;           //setting
DDRB=0b11111111;           //part D as an input part
PORTD=0b11111111;          //Setting
int c;                     //Part B as an output part    
while(1)                           //Pulling up all the pins of part D
  {
  c=PIND;
  if (c==0b11111100)            //straight path
  PORTB=0b00001010;            //forward
  if (c==0b11111110)              //path turns right 
  PORTB=0b00000110;            //right turn
  if (c==0b11111101)            //path turns left  
  PORTB=0b00001001;            //left turn
  if (c==0b11111111)           //crossroad
  {
              //beep and go forward  
PORTB=0b00011010;
  _delay_ms(200);
  }
  }
  }