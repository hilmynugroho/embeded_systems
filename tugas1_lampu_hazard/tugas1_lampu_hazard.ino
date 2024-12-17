#define BUTTON PC5
#define SPST PC3
#define SPDT1 PC1
#define SPDT2 PC0

int main(void){
  DDRB = 0xFF;
  PORTB = 0x00;
  DDRD = 0xFF;
  PORTD = 0x00;
  DDRC = 0x00;

 
  PORTC |= (1 << BUTTON); 
  PORTC |= (1 << SPST);   
  PORTC |= (1 << SPDT1);  
  PORTC |= (1 << SPDT2);
  loop:
    if(!(PINC & (1<<BUTTON))){
      PORTB = 0b00111111;
      PORTD = 0b00000011;
    }

    if(!(PINC & (1<<SPST))){
      PORTB = 0b00001100;
      PORTD = 0b11001111;
      _delay_ms(125);
      for(int i=0;i<250;i++){
        PORTB = 0b00010010;
        PORTD = 0b10000111;
        _delay_us(50);
        PORTB = 0b00001000;
        PORTD = 0b11110111;
        _delay_us(50);
        PORTB = 0b00000100;
        PORTD = 0b11110111;
        _delay_us(50);
        PORTB = 0b00000100;
        PORTD = 0b10111111;
        _delay_us(50);
        PORTB = 0b00001000;
        PORTD = 0b10111111;
        _delay_us(50);
        
      }
      for(int i=0;i<250;i++){
        PORTB = 0b00100001;
        PORTD = 0b00000011;
        _delay_us(50);
        PORTB = 0b00001000;
        PORTD = 0b11111011;
        _delay_us(50);
        PORTB = 0b00000100;
        PORTD = 0b11111011;
        _delay_us(50);
        PORTB = 0b00000100;
        PORTD = 0b01111111;
        _delay_us(50);
        PORTB = 0b00001000;
        PORTD = 0b01111111;
        _delay_us(50);
        PORTB = 0b00010000;
        PORTD = 0b01111111;
        _delay_us(50);
        PORTB = 0b00000010;
        PORTD = 0b01111111;
        _delay_us(50);
        PORTB = 0b00010000;
        PORTD = 0b11111011;
        _delay_us(50);
        PORTB = 0b00000010;
        PORTD = 0b11111011;
        _delay_us(50);
        
      }
      PORTB = 0b00000000;
      PORTD = 0b11111111;
      _delay_ms(125);
    }
    if(!(PINC &(1<<SPDT2))){
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b00111111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b01111111;
        _delay_us(50);
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b00011111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b00111111;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b01111111;
        _delay_us(50);
        
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b10001111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b10011111;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b10111111;
        _delay_us(50);
        
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b11000111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b11001111;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b11011111;
        _delay_us(50);
        
      }
    
      // PORTB = 0b00000000;
      // PORTD = 0b01111111;
      // _delay_ms(125);
    }
    if(!(PINC &(1<<SPDT1))){
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b11110011;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b11111011;
        _delay_us(50);
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b11100011;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b11110011;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b11111011;
        _delay_us(50);
        
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b11000111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b11100111;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b11110111;
        _delay_us(50);
        
      }
      for(int i=0;i<750;i++){
        PORTB = 0b00001100;
        PORTD = 0b10001111;
        _delay_us(50);
        PORTB = 0b00010010;
        PORTD = 0b11001111;
        _delay_us(50);
        PORTB = 0b00100001;
        PORTD = 0b11101111;
        _delay_us(50);
        
      }
    }

    else{
      PORTB = 0x00;
      PORTD = 0x00;
    }
    // _delay_ms(100);
  goto loop;
}