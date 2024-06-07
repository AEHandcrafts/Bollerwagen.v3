#include <Arduino.h>
#include <FastLED.h>

#include "renderer.h"

#include "programs/fade.h"
#include "programs/static-color.h"

#define NUM_LEDS 300
#define LED_PIN 1

CRGB leds[NUM_LEDS];

static_color blue;
fade fade;

renderer<2> program_renderer({&blue, &fade});

void setup() {
  CFastLED::addLeds<WS2812B, LED_PIN, BGR>(leds, NUM_LEDS);
}

void loop() {
  program_renderer.render();
  FastLED.show();
}

void onButtonClick() {
  program_renderer.next();
  FastLED.clear();
}
