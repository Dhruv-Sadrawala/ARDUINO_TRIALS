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

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFFF00
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;

void setup() {

  int rectWidth = 300;
  int rectHeight = 30;  // Menu Items
  int cornerRadius = 10;
  int rectX = 10;
  int rectY = 5;
  
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);

  tft.setCursor(20,15);
  tft.fillRect(rectX, rectY, rectWidth, 50, RED);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("SMART MENU ORDERING ON          TABLE (SMOT)");

  tft.fillRect(10, 60, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(24,68);
  tft.print("Gujarati Thali Rs.210/-");

  tft.fillRect(10, 95, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(24,103);
  tft.print("Punjabi Thali  Rs.200/-");

  tft.fillRect(10, 130, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(24,138);
  tft.print("Marwadi Thali  Rs.220/-");
  
  

  /*tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.fillScreen(WHITE);
  tft.drawRect(10, 60, 300, rectHeight, BLUE);
  tft.print("Gujarati Thali Rs.210/-");

  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.fillScreen(WHITE);
  tft.drawRect(10, 95, 300, rectHeight, BLUE);
  tft.print("Punjabi Thali Rs.200/-");
  
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.fillScreen(WHITE);
  tft.drawRect(10, 130, 300, rectHeight, BLUE);
  tft.print("Marwadi Thali Rs.220/-");
  
  /*tft.fillRect(50,180, 210, 40, RED);
  tft.drawRect(50,180,210,40,BLACK);
  tft.setCursor(60,190);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Please Subscribe");*/

}

void loop() {
  TSPoint p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
    
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
       
   if(p.x>10 && p.x<300 && p.y>60 && p.y<90 && buttonEnabled){
    
    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    tft.fillScreen(WHITE);
    tft.setCursor(100,150);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print(" You have\n\n       ordered\n\n     Gujarati Thali");
   }

   else if(p.x>10 && p.x<300 && p.y>98 && p.y<128 && buttonEnabled){
    
    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    tft.fillScreen(WHITE);
    tft.setCursor(100,150);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print(" You have\n\n       ordered\n\n     Punjabi Thali");
   }  
  }

  else if(p.x>10 && p.x<300 && p.y>129 && p.y<215 && buttonEnabled){
    
    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    tft.fillScreen(WHITE);
    tft.setCursor(100,150);
    tft.setTextColor(BLACK);
    tft.setTextSize(2);
    tft.print(" You have\n\n       ordered\n\n     Marwadi Thali");

  /*tft.fillRect(200, 60, 30, 40, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(24,68);
  tft.print("BACK");

   if(p.x>200 && p.x<240 && p.y>60 && p.y<90 && buttonEnabled)
    setup();
   }  
*/
  }
}
