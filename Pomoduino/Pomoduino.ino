#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); // Pins: DIN,CLK,CS, # of Display connected
int DEFAULT_SCREEN_INTENSITY = 5;
int BUTTON_PIN = 9;

const float POMODORO_DURATION_MINS = 25;
const float PAUSE_DURATION_MINS = 1;

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
  startPomodoro();
  startPause();
}

void startPomodoro() {
  // LEDs will light up one by one, until the matrix is all lit up in POMODORO_DURATION_MINS
  for (int x = 0; x < 8; x ++) {
    for (int y = 0; y < 8; y ++) {
      {
        lc.setLed(0, x, y, true);
        // Wait the appropiate amount of time between LEDs
        delay(getPomodoroDisplayBlockDuration());
      }
    }
  }
}

void startPause() {
  // LEDs will light up in chunks of four, until the matrix is all lit up in PAUSE_DURATION_MINS
  for (int x = 7; x >= 0; x -= 2) {
    for (int y = 7; y >= 0; y -= 2) {
      {
        lc.setLed(0, x, y, true);
        lc.setLed(0, x - 1, y, true);
        lc.setLed(0, x, y - 1, true);
        lc.setLed(0, x - 1, y - 1 , true);
        // Wait the appropiate amount of time between LEDs
        delay(getPauseDisplayBlockDuration());
      }
    }
  }
}

// A display block can either be a single LED or a chunk of four LEDs
int getDisplayBlockDuration(int leds, int minutes) {
  // convert minutes into milliseconds, then divide by the number of LEDs
  float led_duration = minutes * 60000 / leds;
  return ((int) led_duration);
}

int getPomodoroDisplayBlockDuration() {
  // A Pomodoro will use all 64 LEDs individually
  return (getDisplayBlockDuration(64, POMODORO_DURATION_MINS));
}

int getPauseDisplayBlockDuration() {
  // A pause will use chunks of four LEDs
  return (getDisplayBlockDuration(16, PAUSE_DURATION_MINS));
}
