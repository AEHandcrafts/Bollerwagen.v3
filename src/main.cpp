#include <Arduino.h>
#include <FastLED.h>

#define LED_TYPE APA102
#define COLOR_ORDER BGR
#define NUM_LEDS 300
#define DATA_PIN 1
#define CLOCK_PIN 2

int ledCutoff = 154;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

int t = 0;
int color = 0xFF1100;

void loop() {
  t++;

  if (t % 100 == 0) {
    for (int i = 0; i < ledCutoff; i++)
      leds[i] = CRGB::White;
  } else {
    for (int i = 0; i < ledCutoff; i++)
      leds[i] = CRGB(color);
  }

  for (int i = ledCutoff; i < NUM_LEDS; i++)
    leds[i] = CRGB(color);
  FastLED.show();
  delay(8);
}
