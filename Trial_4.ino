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

  tft.fillScreen(WHITE);
}

void loop() {
  drawRoundedRectangleWithText("SMART MENU ORDERING ON          TABLE (SMOT)");
  delay(70000);  // Wait for 5 seconds
}

void drawRoundedRectangleWithText(const char* text) {
  tft.setRotation(-1);
  int rectWidth = 300;
  int rectHeight = 50;  // Adjusted for two lines
  int cornerRadius = 10;
  int rectX = 10;
  int rectY = 5;

  // Draw rounded rectangle
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, RED);

  tft.fillRoundRect(10, 60, 145, rectHeight, cornerRadius, BLUE);

  tft.fillRoundRect(165, 60, 145, rectHeight, cornerRadius, BLUE);

  tft.fillRoundRect(10, 115, 145, rectHeight, cornerRadius, BLUE);

  tft.fillRoundRect(165, 115, 145, rectHeight, cornerRadius, BLUE);

  // Calculate text width and height for each line
  int16_t x, y;
  uint16_t textWidth, textHeight;

  char* line = strtok((char*)text, "\n");
  char* dish_1 = strtok("GUJARATI", "\n");
  while (line != NULL) {
    tft.getTextBounds(line, 0, 20, &x, &y, &rectWidth, &rectHeight);

    // Draw text in the center of the rectangle
    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    int textX = 25;
    int textY = 15;
    tft.setCursor(textX, textY);
    tft.print(line);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(35, 78);
    tft.print(dish_1);

   
  }
}
