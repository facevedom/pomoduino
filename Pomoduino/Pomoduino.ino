#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); // Pins: DIN,CLK,CS, # of Display connected
int DEFAULT_SCREEN_INTENSITY = 5;
int BUTTON_PIN = 9;
int BUZZER_PIN = 15;

const float POMODORO_DURATION_MINS = 30;
const float PAUSE_DURATION_MINS = 5;

String stage = "";
bool skipPause = false;
bool interrupted = false;

void setup()
{
  // Serial communication setup
  Serial.begin(9600);

  // LED matrix setup
  lc.shutdown(0, false); // Wake up display
  lc.setIntensity(0, DEFAULT_SCREEN_INTENSITY);
  lc.clearDisplay(0);

  // Components setup
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start with a greeting
  greet();
}

void loop()
{
  startPomodoro();
  displaychangeSignal();
  startPause();
  displaychangeSignal();
}

void startPomodoro() {
  stage = "pomodoro";
  // LEDs will light up one by one, until the matrix is all lit up in POMODORO_DURATION_MINS
  for (int x = 0; x < 8; x ++) {
    for (int y = 0; y < 8; y ++) {
      {
        lc.setLed(0, x, y, true);
        // Wait the appropiate amount of time between LEDs
        wait(getPomodoroDisplayBlockDuration());
      }
    }
  }
}

void startPause() {
  stage = "pause";
  // LEDs will light up in chunks of four, until the matrix is all lit up in PAUSE_DURATION_MINS
  for (int x = 7; x >= 0; x -= 2) {
    for (int y = 7; y >= 0; y -= 2) {
      {
        lc.setLed(0, x, y, true);
        lc.setLed(0, x - 1, y, true);
        lc.setLed(0, x, y - 1, true);
        lc.setLed(0, x - 1, y - 1 , true);
        // Wait the appropiate amount of time between LEDs
        wait(getPauseDisplayBlockDuration());
        if (skipPause) {
          skipPause = false;
          return;
        }
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

void wait(long interval) {
  int interrupt;
  unsigned long startTime = millis();

  while (millis() - startTime < interval) {
    Serial.println(digitalRead(BUTTON_PIN));
    interrupt = !digitalRead(BUTTON_PIN);
    if (interrupt) {
      interrupted = true;
      if (stage == "pomodoro") {
        while (interrupted) {
          Serial.println(interrupted);
          if (!digitalRead(BUTTON_PIN)) {
            interrupted = false;
          }
          lc.setIntensity(0, 1);
        }
        lc.setIntensity(0, DEFAULT_SCREEN_INTENSITY);
      } else if (stage == "pause") {
        skipPause = true;
        return;
      }
    }
    delay(1);
  }
}
