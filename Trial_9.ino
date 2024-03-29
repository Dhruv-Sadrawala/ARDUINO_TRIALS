#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

/*In this file the successful calling of the review function is done. And the function is printing the number of times a dish is called
with quantity in a specified column.*/

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
TouchScreen ts_2 = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;
boolean dishOrdered = false;

int guj_thali=0;
int jain_thali=0;
int punj_thali=0;

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
  tft.setCursor(70,202);
  tft.print("REVIEW MY ORDER");
}

void review(){

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

  tft.fillRect(rectX, rectY, 300, 50, RED);
  tft.setCursor(100,10);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("YOUR ORDER");

  tft.setCursor(42,35);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("DISH NAME       QTY");

  int yPos = 70;


  if (guj_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("GUJARATI THALI");
    tft.setCursor(245, yPos);
    tft.println(guj_thali);
    yPos += 25;
  }

  if (jain_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("JAIN THALI");
    tft.setCursor(245, yPos);
    tft.println(jain_thali);
    yPos += 25;
  }

  if (punj_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("PUNJABI THALI");
    tft.setCursor(245, yPos);
    tft.println(punj_thali);
  }

  tft.drawRect(10, 187, 145, 45, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(DARK_ORANGE);
  tft.setCursor(52,202);
  tft.print("CLEAR");

  tft.fillRect(165, 187, 145, 45, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(210,202);
  tft.print("ORDER");

}

void con_order(){
 tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.print("order confirmed");
}

void loop() {
  TSPoint p = ts.getPoint();

  if (p.z > ts.pressureThreshhold) {
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);

    if (p.x > 200 && p.x < 230 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      guj_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 160 && p.x < 190 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      jain_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 80 && p.x < 140 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      punj_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 45 && p.x < 90 && p.y > 10 && p.y < 310 && buttonEnabled && dishOrdered) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      review();
      TSPoint p2 = ts.getPoint();
      
      // Review Page
      if (p2.z > ts.pressureThreshhold) {
      p2.x = map(p2.x, TS_MAXX, TS_MINX, 0, 320);
      p2.y = map(p2.y, TS_MAXY, TS_MINY, 0, 240);

        if (p2.x > 45 && p2.x < 90 && p2.y > 155 && p2.y < 300 && buttonEnabled) {
        buttonEnabled = true;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        guj_thali=0;
        jain_thali=0;
        punj_thali=0;
        tft.setTextSize(2);
        tft.setTextColor(BLACK);
        tft.print("clear all null");
        menu();//check this out
        delay(9000);
        } 
        else if (p2.x > 45 && p2.x < 90 && p2.y > 10 && p2.y < 145 && buttonEnabled) {
        buttonEnabled = true;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        tft.setTextSize(2);
        tft.setTextColor(BLACK);
        tft.print("order");
        con_order();
        delay(5000);
        }
      }
    } 
  }
}