#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define BLUE    0x001F

void setup() {
  Serial.begin(9600);

  uint16_t ID = tft.readID();
  Serial.print("ID = 0x");
  Serial.println(ID, HEX);

  tft.begin(ID);

  tft.fillScreen(BLACK);
}

void loop() {
  bouncingBallAnimation(RED, BLUE);
}

void bouncingBallAnimation(uint16_t color1, uint16_t color2) {
  int ballSize = 10;
  int ballSpeedX = 10;  // Increased speed
  int ballSpeedY = 10;

  int ballX = tft.width() / 2 - ballSize / 2;
  int ballY = tft.height() / 2 - ballSize / 2;

  int currentColor = color1;

  for (int i = 0; i < 300; i++) {
    tft.fillScreen(WHITE);

    // Draw the bouncing ball
    tft.fillCircle(ballX, ballY, ballSize, currentColor);

    // Update ball position
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Change color and bounce off the edges
    if (ballX < 0 || ballX > tft.width() - ballSize) {
      ballSpeedX = -ballSpeedX;
      currentColor = (currentColor == color1) ? color2 : color1;  // Change color
    }

    if (ballY < 0 || ballY > tft.height() - ballSize) {
      ballSpeedY = -ballSpeedY;
      currentColor = (currentColor == color1) ? color2 : color1;  // Change color
    }

    delay(1);  // Increased speed
  }
}
