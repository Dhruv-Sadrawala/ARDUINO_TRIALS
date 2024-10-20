#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

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

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 10);

boolean buttonEnabled = true;
boolean dishOrdered = false;

int guj_thali=0;
int jain_thali=0;
int punj_thali=0;
int guj_price=210;
int jain_price=200;
int punj_price=220;

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

  tft.fillRect(10, 182, 300, 50, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(30,192);
  tft.print("PRESS RESET BUTTON TO           ORDER AGAIN");

}

void con_order(){
 tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(10, 10, 300, 220, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(DARK_ORANGE);
  tft.setCursor(18,103);
  tft.print("YOUR ORDER HAS BEEN SENT        TO THE KITCHEN");
}

void bill(){

  int rectX = 10;
  int rectY = 5;
  int total=0;

  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);

  tft.fillRect(rectX, rectY, 300, 50, RED);
  tft.setCursor(103,10);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("YOUR BILL");

  tft.setCursor(42,35);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("DISH NAME    QTY  AMT");

  int yPos = 70;


  if (guj_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("GUJARATI THALI");
    tft.setCursor(210, yPos);
    tft.println(guj_thali);
    tft.setCursor(260, yPos);
    int guj_t=guj_price*guj_thali;
    tft.println(guj_t);
    total+=guj_t;
    yPos += 25;
  }

  if (jain_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("JAIN THALI");
    tft.setCursor(210, yPos);
    tft.println(jain_thali);
    tft.setCursor(260, yPos);
    int jain_t=jain_price*jain_thali;
    tft.println(jain_t);
    total+=jain_t;
    yPos += 25;
  }

  if (punj_thali > 0) {
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(21, yPos);
    tft.print("PUNJABI THALI");
    tft.setCursor(210, yPos);
    tft.println(punj_thali);
    tft.setCursor(260, yPos);
    int punj_t=punj_price*punj_thali;
    tft.println(punj_t);
    total+=punj_t;
  }

  tft.fillRect(10, 150, 300, 30, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,158);
  tft.print("TOATL AMOUNT");
  tft.setCursor(260,158);
  tft.print(total);

  tft.fillRect(10, 182, 300, 50, DARK_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(25,192);
  tft.print("UPI ID 4753XXXXXX@paytm      OR PAY ON COUNTER");
  
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
      tft.fillRect(10, 70, 300, 30, BLUE);
      delay(200);
      tft.setCursor(21,77);
      tft.print("GUJARATI THALI Rs.210/-");
      guj_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 160 && p.x < 190 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      tft.fillRect(10, 110, 300, 30, BLUE);
      delay(200);
      tft.setCursor(21,117);
      tft.print("JAIN THALI     Rs.200/-");
      jain_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 80 && p.x < 150 && p.y > 10 && p.y < 310 && buttonEnabled) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      tft.fillRect(10, 150, 300, 30, BLUE);
      delay(200);
      tft.setCursor(21,157);
      tft.print("PUNJABI THALI  Rs.220/-");
      punj_thali++;
      delay(1000);
      dishOrdered = true;
    } 
    else if (p.x > 45 && p.x < 90 && p.y > 10 && p.y < 310 && buttonEnabled && dishOrdered) {
      buttonEnabled = true;
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      review();
      delay(9000);
      con_order();
      delay(5000);
      bill();
      delay(6000);
    }
  }
}

