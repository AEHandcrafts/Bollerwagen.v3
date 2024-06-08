#include <Arduino.h>
#include <FastLED.h>

#include "matrix.h"
#include "renderer.h"

#include "programs/fade.h"
#include "programs/static-color.h"

#define WIDTH 40    // TODO: set proper width
#define HEIGHT 40   // TODO: set proper height
#define LED_PIN 1   // TODO: set proper led pin
#define BUTTON_PIN 3// TODO: set proper button pin

CRGB leds[WIDTH * HEIGHT];
Matrix matrix(leds, WIDTH, HEIGHT);

Fade fade(matrix);
StaticColor red(matrix, CRGB::Red);
StaticColor green(matrix, CRGB::Green);
StaticColor blue(matrix, CRGB::Blue);
StaticColor white(matrix, CRGB::White);
StaticColor black(matrix, CRGB::Black);
Renderer<6> renderer({&fade, &red, &green, &blue, &white, &black});

void onButtonClick() {
  noInterrupts();
  renderer.next();
  FastLED.clear();
  interrupts();
}

void setup() {
  CFastLED::addLeds<WS2812B, LED_PIN, BGR>(leds, WIDTH * HEIGHT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonClick, RISING);
}

void loop() {
  renderer.render();
  FastLED.show();
}
