#ifndef LEDMatrix_h
#define LEDMatrix_h

#include "Arduino.h"

class LEDMatrix
{
  public:
    LEDMatrix();
    void clearScreen();
    void refreshScreen();
    void lightPixel(int x, int y);
  private:
    // row pins on the matrix: 12, 15, 10, 16, 5, 9, 3, 8
    const int _row[8] = {
      // actual row pins on the Arduino
      6, 3, 8, 2, 15, 9, 17, 11
    };

    // col pins on the matrix: 1, 2, 6, 11, 7, 13, 14, 4
    const int _col[8] = {
      // actual col pins on the Arduino
      19, 18, 14, 7, 10, 5, 4, 16
    };

    int _pixels[8][8];
};

#endif
