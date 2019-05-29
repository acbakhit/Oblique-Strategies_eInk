t#include <GxEPD.h>
#include <GxGDEH029A1/GxGDEH029A1.cpp>      // 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
#include "Obli_q.h"


GxIO_Class io(SPI, SS, 22, 21); 
GxEPD_Class display(io, 16, 4); 


void setup() {
  display.init();
  display.fillScreen(GxEPD_WHITE);
  display.update();
  display.setRotation(0);

}
  

void loop() {

  while (1){
  int n = random(0, 128);
  display.drawExampleBitmap(IMAGE[n], 0, 0, GxEPD_WIDTH,GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  esp_sleep_enable_timer_wakeup(86400000000);
  esp_deep_sleep_start();
  }
  
}
