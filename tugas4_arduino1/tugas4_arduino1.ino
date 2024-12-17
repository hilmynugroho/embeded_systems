// #include <avr/io.h>
// #include <stdio.h>

// void setup() {
//   Serial.begin(9600);  // Initialize serial communication
//   pinMode(12, INPUT_PULLUP);  // Button 1
//   pinMode(13, INPUT_PULLUP);  // Button 2
// }

// void loop() {
//   if (digitalRead(12) == LOW) {  // Check if Button 1 is pressed
//     Serial.println("LED1_ON");
    
//   } else {
//     Serial.println("LED1_OFF");
//   }
//   if (digitalRead(13) == LOW) {  // Check if Button 2 is pressed
//     Serial.println("LED2_ON");
    
//   } else {
//     Serial.println("LED2_OFF");
//   }
//   delay(20);
// }

int main(){
  USART_Init();

  DDRB = 0xFF;
  PORTB |= (1 << PB4) | (1 << PB5);

  loop:
    if (!(PINB & (1 << PB4))){
      USART_Write("1\n");
    } else {
      USART_Write("0\n");
    }
    if (!(PINB & (1 << PB5))){
      USART_Write("3\n");
    } else {
      USART_Write("2\n");
    }
    _delay_ms(200);
  goto loop;
}


void USART_Init() {
    UBRR0H = 0; 
    UBRR0L = 103;  
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // Enable RX and TX
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}


void USART_Write(char *str) {
    while (*str) {
        while (!(UCSR0A & (1 << UDRE0))); 
        UDR0 = *str++;  // Send data and move to the next character
    }
}

// void USART_WriteString(char *str) {
//     while (*str) {
//         USART_Write(*str++);
//     }
// }