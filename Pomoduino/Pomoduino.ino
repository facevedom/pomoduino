#include <LEDMatrix.h>

LEDMatrix led;
const float pomodoro_duration_mins = 25;
const float pause_duration_mins = 5;

void setup() {
  Serial.begin(9600);
  flashThreeTimes();
  greet();
}

void loop() {  
  for (int pomodoros = 0; pomodoros < 4; pomodoros ++) {
    startPomodoro();
    led.clearScreen();
    flashThreeTimes();
    led.clearScreen();
    startPause();
    led.clearScreen();
    flashThreeTimes();
  }

  exit(0);
}

// This is how long each LED should be on to fill the matrix in the requested minutes
int getLedDuration(bool pause) {
  int leds;
  float minutes;

  if (pause) {
    leds = 8;
    minutes = pause_duration_mins;
  } else {
    leds = 64;
    minutes = pomodoro_duration_mins;
  }

  // convert minutes into milliseconds, then divide by the number of LEDs
  float led_duration = minutes * 60000 / leds;
  return ((int) led_duration);
}

void startPomodoro() {
  Serial.println("Starting Pomodoro");

  for (int x = 0; x < 8; x ++) {
    for (int y = 0; y < 8; y ++) {
      {
        led.lightPixel(x, y);
        wait(getLedDuration(false));
      }
    }
  }
}

void startPause() {
  for (int x = 7; x >= 0; x --) {
    for (int y = 0; y < 8; y ++) {
      led.lightPixel(x, y);
    }
    wait(getLedDuration(true));
  }
}


void wait(long interval) {
  unsigned long startTime = millis();

  while (millis() - startTime < interval) {
    led.refreshScreen();
  }
}
