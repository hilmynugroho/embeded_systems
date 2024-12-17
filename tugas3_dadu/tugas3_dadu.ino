#define BUTTON_PIN PC5

void LightDice(int d1, int d2) {
  switch (d1) {
      case 1: PORTB = 0b00001000; break; // 1
      case 2: PORTB = 0b00010000; break; // 2
      case 3: PORTB = 0b00101000; break; // 3
      case 4: PORTB = 0b00100100; break; // 4
      case 5: PORTB = 0b00101100; break; // 5
      case 6: PORTB = 0b00110100; break; // 6
  }

  switch (d2) {
      case 1: PORTD = 0b00010000; break; // 1
      case 2: PORTD = 0b00001000; break; // 2
      case 3: PORTD = 0b00110000; break; // 3
      case 4: PORTD = 0b00100100; break; // 4
      case 5: PORTD = 0b00110100; break; // 5
      case 6: PORTD = 0b00101100; break; // 6
  }
}

int main() {
  DDRB = 0xff; 
  DDRD = 0xff; 
  PORTC |= (1 << BUTTON_PIN); 

  unsigned int seed = 0; 

  loop:
    while (PINC & (1 << BUTTON_PIN)) {
      seed++; 
      _delay_ms(1); 
    } 
    srand(seed);

      if (!(PINC & (1 << BUTTON_PIN))) { 
          int d1 = rand() % 6 + 1; 
          int d2 = rand() % 6 + 1; 
          LightDice(d1, d2);
          _delay_ms(500);
      }
  goto loop;
}