#include <Arduino.h>

void setup()
{
    DDRD &= ~(1 << 2);   // D2 as INPUT (PIR Sensor)
    DDRB |= (1 << 0);    // D8 as OUTPUT (Status LED)
    DDRB |= (1 << 1);    // D9 as OUTPUT (Alert LED)
    DDRB |= (1 << 2);    // D10 as OUTPUT (Buzzer)

    // PIR Warm-up Time
    delay(30000);
}

void loop()
{
    // Blink Status LED
    
    PORTB |= (1 << 0);    // D8 HIGH
    delay(1000);

    PORTB &= ~(1 << 0);   // D8 LOW
    delay(1000);

    // Read PIR Sensor
    
    if (PIND & (1 << 2))   // Check D2
    {
        // Motion Detected

        PORTB |= (1 << 1);   // Alert LED ON
        PORTB |= (1 << 2);   // Buzzer ON

        delay(5000);

        PORTB &= ~(1 << 1);  // Alert LED OFF
        PORTB &= ~(1 << 2);  // Buzzer OFF
    }
}
