#include <Arduino.h>
#include <FastLED.h>

#include "matrix.h"
#include "renderer.h"

#include "programs/fade.h"
#include "programs/static-color.h"

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define WIDTH 37
#define HEIGHT 9
#define LED_PIN 1    // D1 on the board
#define BUTTON_PIN D3// D3 on the board

CRGB leds[WIDTH * HEIGHT];
Matrix matrix(leds, WIDTH, HEIGHT);

Fade fade(matrix);
StaticColor red(matrix, CRGB::Red);
StaticColor green(matrix, CRGB::Green);
StaticColor blue(matrix, CRGB::Blue);
StaticColor white(matrix, CRGB::White);
StaticColor black(matrix, CRGB::Black);
Renderer<6> renderer({&fade, &red, &green, &blue, &white, &black});

IRAM_ATTR void onButtonClick() {
  renderer.next();
}

void setup() {
  CFastLED::addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, WIDTH * HEIGHT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(BUTTON_PIN, &onButtonClick, RISING);
}

void loop() {
  renderer.render();
  FastLED.show();
}
