
#include "epd1in54_V2.h"
#include "imagedata.h"
#include "epdpaint.h"


#define COLORED     0
#define UNCOLORED   1


//unsigned char image[1024];
//Paint paint(image,0,0);    // width should be the multiple of 8 
Epd epd;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (epd.Init() != 0) {
      Serial.println("e-Paper init failed");
      return;
  }
	Serial.println("show pic");
	epd.Display(IMAGE_DATA);
  Serial.println("end");
  while(1);
}

void loop()
{

}
