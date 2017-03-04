#include <Adafruit_NeoPixel.h>
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
 #include <avr/power.h>
#endif

#define PIN 0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);

uint32_t offset = 0; // Position of spinny eyes
uint32_t color  = 0x00FF00; // green

void setup() {
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
    if(F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
    pixels.begin();
    pixels.setBrightness(85); // 1/3 brightness
}

void loop() {
    uint8_t  i;
    uint32_t t;

    pixels.setPixelColor(offset, color);
    pixels.setPixelColor(offset+1 % 16, color);
    pixels.setPixelColor(offset+16, color);
    pixels.setPixelColor(offset+17 % 16, color);
    pixels.show();
    delay(50);
    for(i=0; i<32; i++) { 
        pixels.setPixelColor(i, 0);
    }
    offset++;
    offset = offset % 16;
}
