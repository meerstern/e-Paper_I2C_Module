/**
 *  @filename   :   epdif.cpp
 *  @brief      :   Implements EPD interface functions
 *                  Users have to implement all the functions in epdif.cpp
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "epdif.h"
#include <Wire.h>
#include "SC18IS602.h"

SC18IS602 i2cspi=SC18IS602(SC18IS602_ADDRESS_000);

EpdIf::EpdIf() {
};

EpdIf::~EpdIf() {
};

void EpdIf::DigitalWrite(int pin, int value) {
    i2cspi.digitalWrite(pin, value);
}

int EpdIf::DigitalRead(int pin) {
    return i2cspi.digitalRead(pin);
}

void EpdIf::DelayMs(unsigned int delaytime) {
    delay(delaytime);
}

void EpdIf::SpiTransfer(unsigned char data) {
    // digitalWrite(CS_PIN, LOW);
    // SPI.transfer(data);
    // digitalWrite(CS_PIN, HIGH);
	//i2cspi.digitalWrite(CS_PIN, LOW);
	i2cspi.transfer(&data,1);
	//i2cspi.digitalWrite(CS_PIN, HIGH);
}

int EpdIf::IfInit(void) {
    // pinMode(CS_PIN, OUTPUT);
    // pinMode(RST_PIN, OUTPUT);
    // pinMode(DC_PIN, OUTPUT);
    // pinMode(BUSY_PIN, INPUT); 
    // SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    // SPI.begin();
	i2cspi.begin();
	return 0;
}

