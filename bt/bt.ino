#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include <SoftwareSerial.h>  //  Seri Haberleşme kütüphanesini ekledik
SoftwareSerial BTSerial(10, 11); // RX, TX  // BT için ayrıca bir Seri Haberleşmesi

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16       
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };


void setup()   {                
  Serial.begin(9600);
  BTSerial.begin(9600);
}


void loop() {
  while(BTSerial.available()) 
    Serial.print((char)BTSerial.read());
  
  while (Serial.available())
      BTSerial.write(Serial.read());  
}


