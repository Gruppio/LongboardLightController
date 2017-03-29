#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN   2
#define NUM_PIXELS  36
#define HALF_NUM_PIXELS NUM_PIXELS/2

#define COLOR uint32_t
#define COLOR_INTENSITY 255

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
}

byte color = 0;
void loop() {
    for (int i = 0; i < HALF_NUM_PIXELS; i++) {
        byte phase = (255 / HALF_NUM_PIXELS) * i;
        byte phasedColor = color + phase;
        setPixelColorSymmetric(i, getColorWheel(phasedColor));
        color--;
    }
    pixels.show();
    delay(50);
}

void setPixelColorSymmetric(int index, COLOR color) {
    pixels.setPixelColor(index, color);
    pixels.setPixelColor(NUM_PIXELS - index, color);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t getColorWheel(byte index) {
    if(index < 85) {
        return pixels.Color(index * 3, 255 - index * 3, 0);
    } else if(index < 170) {
        index -= 85;
        return pixels.Color(255 - index * 3, 0, index * 3);
    } else {
        index -= 170;
        return pixels.Color(0, index * 3, 255 - index * 3);
    }
}

/*
byte color = 0;
void loop() {
    setAllPixelsColor(getColorWheel(color++));
    delay(50);
}
*/
