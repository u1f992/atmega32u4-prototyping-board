#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // PD0: Active low output
  DDRD |= (1 << PD0);

  while (1) {
    // LOWで点灯
    PORTD &= ~(1 << PD0);
    _delay_ms(500);

    // HIGHで消灯
    PORTD |= (1 << PD0);
    _delay_ms(500);
  }
}
