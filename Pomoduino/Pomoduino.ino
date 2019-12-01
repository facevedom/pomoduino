#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); // Pins: DIN,CLK,CS, # of Display connected
int DEFAULT_SCREEN_INTENSITY = 5;
int BUTTON_PIN = 9;

void setup()
{
  // Serial communication setup
  Serial.begin(9600);

  // LED matrix setup
  lc.shutdown(0, false); // Wake up display
  lc.setIntensity(0, DEFAULT_SCREEN_INTENSITY); // Set intensity level
  lc.clearDisplay(0);    // Clear Display

  // Button setup
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Start with a greeting
  greet();
}

void loop()
{
  int val = digitalRead(BUTTON_PIN);
}
