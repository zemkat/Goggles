/*
  green_tailfade.ino - spinning animation with long fading tail
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
uint32_t tail_length  = 5; // 
uint32_t scoot_delay  = 100; // control speed
uint32_t bright[5] = {5,10,25,100,255}; // manual for now

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
    // first eye has pixels 0-15, second has 16-31
    for (int j=0;j<tail_length;j++) {
        int real_offset = (offset+j) % 16;
        pixels.setPixelColor(real_offset, 0, bright[j], 0); // first eye
        pixels.setPixelColor(real_offset+16, 0, bright[j], 0); // second
    }
    pixels.show();
    delay(scoot_delay);
    for(i=0; i<32; i++) { // blank all pixels
        pixels.setPixelColor(i, 0);
    }
    offset++;
    offset = offset % 16;
}
