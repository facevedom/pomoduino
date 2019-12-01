const int GREETING_SCREEN_DELAY = 600; // Display time of each of the greeting screens

const byte greeting_screens[5][8] =
{
  { B11110000, B10010000, B10010000, B11110000, B10000000, B10000111, B00000101, B00000111 },
  { B10001000, B11011000, B10101000, B10001000, B10001000, B00000111, B00000101, B00000111 },
  { B00000000, B00000000, B11001010, B10101010, B10101010, B11001110, B00000000, B00000000 },
  { B00000000, B00000000, B11101001, B01001101, B01001011, B11101001, B00000000, B00000000 },
  { B00000000, B00000000, B00111100, B00100100, B00100100, B00111100, B00000000, B00000000 }
};

void greet() {
  // Number of screens in the greeting
  int screen_count = sizeof(greeting_screens) / sizeof(greeting_screens)[0];

  // Display all of the greeting screens
  for (int i = 0; i < screen_count; i++) {
    displayScreen(greeting_screens[i]);
    delay(GREETING_SCREEN_DELAY);
  }

  // Gradually dim the screen
  for (int i = DEFAULT_SCREEN_INTENSITY; i > 0; i--) {
    lc.setIntensity(0, i);
    delay(300);
  }

  // Clear the screen and return to normal intensity level
  lc.clearDisplay(0);    // Clear Display
  lc.setIntensity(0, DEFAULT_SCREEN_INTENSITY); // Set intensity level
}

void displayScreen(byte screen[]) {
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, screen[i]);
  }
}

// Flash the screen three times
void displaychangeSignal() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, B11111111);
    }
    
    delay(300);
    lc.clearDisplay(0);
    delay(300);
  }
}
