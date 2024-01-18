#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define WHITE   0xFFFF

void setup() {
  Serial.begin(9600);

  uint16_t ID = tft.readID();
  Serial.print("ID = 0x");
  Serial.println(ID, HEX);

  tft.begin(ID);

  tft.fillScreen(WHITE);
}

void loop() {
  question();
  delay(5000);  // Wait for 5 seconds
  tft.fillScreen(WHITE);  // Clear the screen after 5 seconds
  answer();
  delay(5000);
}

void question() {
  tft.setTextSize(2);
  tft.setTextColor(BLACK);

  tft.setCursor(39, 30);
  tft.print("You know whats");
  tft.setCursor(70,40 + 10);
  tft.print(" ");
  tft.print("30+40 ?");
}

void answer() {
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  
  tft.setCursor(80,150);
  tft.print("Its 70");
  tft.setCursor(100,160 + 10);
  tft.print(" ");
  tft.print(":)");
  
}