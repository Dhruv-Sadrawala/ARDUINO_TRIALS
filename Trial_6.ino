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
#define LIGHT_RED	0xFD14
#define RED     0xF800
#define DARK_RED    0x6000
#define LIGHT_ORANGE 0xFF52
#define ORANGE  0xFD00
#define DARK_ORANGE 0xFA80
#define LIGHT_YELLOW 0xFFF4
#define YELLOW  0xD7E0
#define DARK_YELLOW 0xCE40
#define LIGHT_GREEN 0xB7F6
#define GREEN   0x07E0
#define DARK_GREEN 0x0320
#define LIGHT_BLUE 0xA51F
#define BLUE    0x001F
#define DARK_BLUE 0x000C
#define PURPLE  0xF81F
#define CYAN    0x07FF
#define GREY    0x8410
#define WHITE   0xFFFF


Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;

int roti_co=0;
int H2O_co=0;
int dal_co=0;
int rice_co=0;

void setup() {
  int rectWidth = 145;
  int rectHeight = 50;  // Menu Items
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
  tft.setCursor(21,86);
  tft.print("Roti Rs.20");

  tft.fillRect(165, 70, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(178,86);
  tft.print("H2O Rs.15");

  tft.fillRect(10, 130, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(21,146);
  tft.print("Dal Rs.100");

  tft.fillRect(165, 130, rectWidth, rectHeight, BLUE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(172,146);
  tft.print("Rice Rs.120");

  tft.fillRect(10,185, 300, 45, LIGHT_ORANGE);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(90,199);
  tft.print("Review Order");

}

void loop() {
  TSPoint p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
    
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);

   if(p.x>10 && p.x<155 && p.y>70 && p.y<120 && buttonEnabled){

    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  
    tft.fillScreen(WHITE);
    tft.fillRect(0,0,319,240,RED);

    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(130,120);
    tft.print("You odered roti");
   }

  /*else if(p.x>165 && p.x<310 && p.y>50 && p.y<120 && buttonEnabled){
    
    H2O_co++;
    tft.setTextColor(BLACK);
    tft.setCursor(130,120);
    tft.print("You odered H2O");
   }  
  
  else if(p.x>10 && p.x<155 && p.y>130 && p.y<180 && buttonEnabled){
    
    dal_co++;
    tft.setTextColor(BLACK);
    tft.setCursor(130,120);
    tft.print("You odered Dal");
  }

  else if(p.x>10 && p.x<310 && p.y>130 && p.y<180 && buttonEnabled){
    
    rice_co++;
    tft.setTextColor(BLACK);
    tft.setCursor(130,120);
    tft.print("You odered rice");
  }

  else if(p.x>10 && p.x<310 && p.y>175 && p.y<225 && buttonEnabled){
    
    review();
      buttonEnabled = false; // Disable buttons to prevent multiple calls during the delay
      delay(7000);  // Reduced delay for testing purposes, adjust as needed
      buttonEnabled = true;

  }*/
 }

}
