#include <Arduino.h>
#include <FastLED.h>

#include "matrix.h"
#include "renderer.h"

#include "programs/fade.h"
#include "programs/horizontal-fade.h"
#include "programs/noise.h"
#include "programs/static-color.h"

#define LED_COLOR_ORDER GRB
#define LED_PIN 1    // D1 on the board
#define BUTTON_PIN D3// D3 on the board

Matrix matrix(37, 10, MatrixMapping::BOTTOM_RIGHT_ZIGZAG);
Fade fade(matrix);
HorizontalFade horizontalFade(matrix);
StaticColor red(matrix, CRGB::Red);
StaticColor green(matrix, CRGB::Green);
StaticColor blue(matrix, CRGB::Blue);
StaticColor white(matrix, CRGB::White);
StaticColor black(matrix, CRGB::Black);
Noise noise(matrix, CRGB::White);
Renderer renderer({&fade, &horizontalFade, &red, &green, &blue, &white, &black, &noise});

IRAM_ATTR void onButtonClick() {
  renderer.next();
}

void setup() {
  CFastLED::addLeds<WS2812B, LED_PIN, LED_COLOR_ORDER>(matrix.leds, matrix.width * matrix.height);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, onButtonClick, RISING);
}

void loop() {
  renderer.render();
  FastLED.show();
}
