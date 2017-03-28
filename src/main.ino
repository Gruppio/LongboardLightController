#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN   2
#define NUM_PIXELS  18

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
}

void loop() {
    setAllPixelsColor(0, 0, 50);
    pixels.show();
    delay(1000);
}

/*
void setAllPixelsColor(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        pixels.setPixelColor(i, r, g, b);
    }
    pixels.show();
}

void displayNumberOfActiveUsers(int numberOfActiveUsers) {
    uint8_t colorIntensity = 80;
    uint32_t color1x = pixels.Color(0, colorIntensity, 0);
    uint32_t color2x = pixels.Color(colorIntensity, colorIntensity, 0);
    uint32_t color3x = pixels.Color(colorIntensity, 0, 0);
    uint32_t color4x = pixels.Color(colorIntensity, colorIntensity, colorIntensity);

    int remainingUsers = numberOfActiveUsers;
    int numberOfUsersValue1x = 1;
    int numberOfUsersValue2x = numberOfUsersValue1x * NUM_PIXELS;
    int numberOfUsersValue3x = numberOfUsersValue2x * NUM_PIXELS;
    int numberOfUsersValue4x = numberOfUsersValue3x * NUM_PIXELS;

    int numberOfPixels1x = 0;
    int numberOfPixels2x = 0;
    int numberOfPixels3x = 0;
    int numberOfPixels4x = 0;

    while (remainingUsers >= numberOfUsersValue4x) {
        remainingUsers -= numberOfUsersValue4x;
        numberOfPixels4x++;
    }

    while (remainingUsers >= numberOfUsersValue3x) {
        remainingUsers -= numberOfUsersValue3x;
        numberOfPixels3x++;
    }

    while (remainingUsers >= numberOfUsersValue2x) {
        remainingUsers -= numberOfUsersValue2x;
        numberOfPixels2x++;
    }

    while (remainingUsers >= numberOfUsersValue1x) {
        remainingUsers -= numberOfUsersValue1x;
        numberOfPixels1x++;
    }

    pixels.clear();
    int numberOfPixelsToSet = numberOfPixels1x + numberOfPixels2x + numberOfPixels3x + numberOfPixels4x;

    for (int pixelIndex = 0;pixelIndex < numberOfPixelsToSet; pixelIndex++) {
        if (numberOfPixels4x) {
            numberOfPixels4x--;
            pixels.setPixelColor(pixelIndex, color4x);
            pixels.show();
            continue;
        }

        if (numberOfPixels3x) {
            numberOfPixels3x--;
            pixels.setPixelColor(pixelIndex, color3x);
            pixels.show();
            continue;
        }

        if (numberOfPixels2x) {
            numberOfPixels2x--;
            pixels.setPixelColor(pixelIndex, color2x);
            pixels.show();
            continue;
        }

        if (numberOfPixels1x) {
            numberOfPixels1x--;
            pixels.setPixelColor(pixelIndex, color1x);
            pixels.show();
            continue;
        }
    }
}
*/
