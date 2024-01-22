#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

/*In this file the successful calling of the review function is done. And successful taking of multiple dishes by clicking n number of times*
Still the values of dishes are printing absurd values.*/

#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890


#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define BLACK   0x0
#define WHITE   0xFFFF
#define BLUE    0x001F
#define RED     0xF800
#define DARK_ORANGE 0xFA80

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;
boolean dishOrdered = false;

void setup() {
  menu();
  
}

void menu(){
  int rectWidth = 300;
  int rectHeight = 30;  // Menu Items
  int rectX = 10;
  int rectY = 5;

  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);

  tft.setCursor(20,15);
  tft.fillRect(rectX, rectY, 300, 50, RED);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("SMART MENU ORDERING ON          TABLE (SMOT)");

  tft.fillRect(10, 70, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,77);
  tft.print("GUJARATI THALI Rs.210/-");

  tft.fillRect(10, 110, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,117);
  tft.print("JAIN THALI     Rs.200/-");

  tft.fillRect(10, 150, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,157);
  tft.print("PUNJABI THALI  Rs.220/-");

  
  tft.fillRect(10, 187, 300, 45, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(70,200);
  tft.print("REVIEW MY ORDER");
}

void review(int guj_co,int jain_co,int punj_co){

  int rectWidth = 300;
  int rectHeight = 30;  // Menu Items
  int rectX = 10;
  int rectY = 5;

  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);

  tft.setCursor(50,20);
  tft.fillRect(rectX, rectY, 300, 50, RED);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("YOUR ORDER");

  tft.fillRect(10, 70, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,77);
  tft.print("GUJARATI THALI-");
  tft.print(guj_co);

  tft.fillRect(10, 110, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,117);
  tft.print("JAIN THALI:&jain_thali");

  tft.fillRect(10, 150, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,157);
  tft.print("PUNJABI THALI:&punj_thali");

}

void loop() {
  TSPoint p = ts.getPoint();

int guj_thali=0;
int jain_thali=0;
int punj_thali=0;
  

  if (p.z > ts.pressureThreshhold) {
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);

    if (p.x > 200 && p.x < 230 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      guj_thali++;
      tft.setTextSize(2);
      tft.setTextColor(BLACK);
      tft.setCursor(50, 150);
      tft.print("Gujarati thali");
      tft.print(guj_thali);
      dishOrdered = true;
    } else if (p.x > 160 && p.x < 190 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      jain_thali++;
      tft.setTextSize(2);
      tft.setTextColor(BLACK);
      tft.setCursor(50, 150);
      tft.print("jain called");
      dishOrdered = true;
    } else if (p.x > 80 && p.x < 140 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      punj_thali++;
      tft.setTextSize(2);
      tft.setTextColor(BLACK);
      tft.setCursor(50, 150);
      tft.print("Punjabi called");
      dishOrdered = true;
    } else if (p.x > 45 && p.x < 90 && p.y > 10 && p.y < 310 && buttonEnabled && dishOrdered) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      review(guj_thali,jain_thali,punj_thali);
      delay(5000);
    }
  }
}
