#include <LEDMatrix.h>

LEDMatrix led;

void setup()
{

}

void loop() {
  led.lightPixel(1, 4);
  led.refreshScreen();
}
