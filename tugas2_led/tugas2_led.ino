#define BUTTON PD2

volatile uint8_t state = 0;
volatile uint8_t button = 0;

int main(){
  DDRB = 0b00111111;
  PORTB = 0x00;
  DDRD &= ~(1 << BUTTON);
  PORTD |= (1 << BUTTON);

  EICRA |= (1 << ISC01); 
  EIMSK |= (1 << INT0);   

  TCCR0A |= (1 << WGM01); // CTC mode
  TCCR0B |= (1 << CS02) | (1 << CS00); // Prescaler 1024
  OCR0A = 156; // Compare match for ~10 ms at 16 MHz clock
  TIMSK0 |= (1 << OCIE0A); 

  sei(); 
  while(1){

  }
}

ISR(TIMER0_COMPA_vect) {
  if (button) {
    button = 0; 
    state = (state + 1) % 8;
    switch (state) {
      case 0: PORTB = 0x00; break;          
      case 1: PORTB = 0b00000001; break; 
      case 2: PORTB = 0b00100001; break; 
      case 3: PORTB = 0b00100011; break; 
      case 4: PORTB = 0b00110011; break; 
      case 5: PORTB = 0b00110111; break;
      case 6: PORTB = 0b00111111; break; 
      case 7: PORTB = 0b00101010; break;   
    }
  }
}


ISR(INT0_vect) {
  if (!(PIND & (1 << BUTTON))) {
    button = 1; 
  }
}