const int screen_1[8][8] = {
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 0, 0, 1, 0, 0, 0, 0},
  {1, 0, 0, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 1}
};

const int screen_2[8][8] = {
  {1, 0, 0, 0, 1, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {1, 0, 1, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 1}
};

const int screen_3[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 0, 0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1, 0, 1, 0},
  {1, 1, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const int screen_4[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 1, 0, 1},
  {0, 1, 0, 0, 1, 0, 1, 1},
  {1, 1, 1, 0, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

const int screen_5[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};


void greetingDisplayScreen(int screen[8][8])
{
  unsigned long startTime = millis();
  const long interval = 600;

  for (int x = 0; x < 8; x ++)
  {
    for (int y = 0; y < 8; y ++)
    {
      if (screen[x][y])
        led.lightPixel(x, y);
    }
  }

  while (millis() - startTime < interval)
  {
    led.refreshScreen();
  }
  led.clearScreen();
  delay(200);
}

void greet()
{
  greetingDisplayScreen(screen_1);
  greetingDisplayScreen(screen_2);
  greetingDisplayScreen(screen_3);
  greetingDisplayScreen(screen_4);
  greetingDisplayScreen(screen_5);
}
