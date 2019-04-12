/*
 * Modified by Navaneeth Krishnan, For Elementz Engineers Guild Pvt Ltd
*/
#include <GxEPD.h>
#include <GxGDEH029A1/GxGDEH029A1.cpp>      // 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
#include <Fonts/FreeSansBold24pt7b.h>
GxIO_Class io(SPI, SS, 22, 21); 
GxEPD_Class display(io, 16, 4); 

#include <SPI.h>
#include "epd2in9.h"
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED     1
#define UNCOLORED   0

const char* name = "FreeSansBold24pt7b";
const GFXfont* f = &FreeSansBold24pt7b;

unsigned char image[1024];
Paint paint(image, 0, 0); 
Epd epd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (epd.Init(lut_full_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  }
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  display.init();
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.update();
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(50, 15);
  display.println();
  display.println(" Daily Quote");

  //epd.SetFrameMemory(IMAGE_DATA);
  //epd.DisplayFrame();
  //epd.SetFrameMemory(IMAGE_DATA);
  //epd.DisplayFrame();  

  paint.SetRotate(ROTATE_90);
  //paint.SetWidth(128);
  //paint.SetHeight(24);
  paint.SetWidth(24);
  paint.SetHeight(256);

  //paint.Clear(COLORED);
  //paint.DrawStringAt(0, 0, "DEMO", &Font12, UNCOLORED);
  //epd.SetFrameMemory(paint.GetImage(), 75, 250, paint.GetWidth(), paint.GetHeight());
  //epd.DisplayFrame();

  paint.Clear(COLORED);
  paint.DrawStringAt(50, 4, "Oblique Strategies", &Font16, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 50, 4, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  paint.Clear(COLORED);
  paint.DrawStringAt(75, 4, "Think of the radio", &Font12, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 50, 0, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  delay(5000);
  paint.Clear(COLORED);
  paint.DrawStringAt(80, 4, "Remove specifics", &Font12, UNCOLORED);
  paint.DrawStringAt(50, 16, "and convert to ambiguities", &Font12, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 50, 0, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  delay(5000);
  paint.Clear(COLORED);
  paint.DrawStringAt(45, 4, "Don't be frightened of cliches", &Font12, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 50, 0, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  delay(5000);
  paint.Clear(COLORED);
  paint.DrawStringAt(80, 4, "Allow an easement", &Font12, UNCOLORED);
  paint.DrawStringAt(25, 16, "(an easement is the abandonment of a stricture)", &Font8, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 50, 0, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  delay(5000);

}
