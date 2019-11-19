// row pins on the matrix: 12, 15, 10, 16, 5, 9, 3, 8
const int row[8] = {
  6, 3, 8, 2, 15, 9, 17, 11
};

// col pins on the matrix: 1, 2, 6, 11, 7, 13, 14, 4
const int col[8] = {
  19, 18, 14, 7, 10, 5, 4, 16
};

int pixels[8][8];

void setup()
{
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
  }

  // initialize the pixel matrix:
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = HIGH;
    }
  }
}

void loop() {
  pixels[0][0] = LOW;
  pixels[3][4] = LOW;
  refreshScreen();
}

void refreshScreen() {
  // iterate over the rows (anodes):
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    // take the row pin (anode) high:
    digitalWrite(row[thisRow], HIGH);
    // iterate over the cols (cathodes):
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the row is HIGH and the col is LOW,
      // the LED where they meet turns on:
      digitalWrite(col[thisCol], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    // take the row pin low to turn off the whole row:
    digitalWrite(row[thisRow], LOW);
  }
}
