/*
  green_simple.ino - simple spinning green animation 
  sketch for Adafruit Neopixel goggles, based on tutorial example
  Kathryn Lybarger (@zemkat)
*/
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

    pixels.setPixelColor(offset, color); // first eye
    pixels.setPixelColor(offset+1 % 16, color); // first eye
    pixels.setPixelColor(offset+16, color); // second eye
    pixels.setPixelColor(offset+17 % 16, color); // second eye
    pixels.show();
    delay(50);
    for(i=0; i<32; i++) { // clear all pixels
        pixels.setPixelColor(i, 0);
    }
    offset++; // scoot position
    offset = offset % 16; // keep between 0 and 15
}
