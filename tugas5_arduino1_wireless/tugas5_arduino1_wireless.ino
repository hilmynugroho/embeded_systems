
#define BUTTON1 PB4 
#define BUTTON2 PB5 
#define IR_LED  PB2  

int main(){
  DDRB = (1 << IR_LED);
  PORTB |= (1 << BUTTON1) | (1 << BUTTON2);
  loop:
    if(!(PINB & (1 << BUTTON1))){
      PORTB |= (1 << IR_LED);
      _delay_ms(100);
    }
    else if(!(PINB & (1 << BUTTON2))){
      for(int i=0;i<100;i++){
        PORTB |= (1 << IR_LED);
        _delay_us(13);
        PORTB &= ~(1 << IR_LED);
        _delay_us(13);
      }
    }else{
      PORTB &= ~(1 << IR_LED);
    }
  goto loop;
}
