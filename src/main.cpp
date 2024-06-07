#include <Arduino.h>
#include <FastLED.h>

#include "matrix.h"
#include "renderer.h"

#include "programs/fade.h"
#include "programs/static-color.h"

#define NUM_LEDS 300
#define LED_PIN 1

CRGB leds[NUM_LEDS];
Matrix matrix(leds, 10, 50);

Fade fade(matrix);
StaticColor red(matrix, CRGB::Red);
StaticColor green(matrix, CRGB::Green);
StaticColor blue(matrix, CRGB::Blue);
StaticColor white(matrix, CRGB::White);
StaticColor black(matrix, CRGB::Black);
Renderer<6> renderer({&fade, &red, &green, &blue, &white, &black});

void setup() {
  CFastLED::addLeds<WS2812B, LED_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
  renderer.render();
  FastLED.show();
}

void onButtonClick() {
  renderer.next();
  FastLED.clear();
}
