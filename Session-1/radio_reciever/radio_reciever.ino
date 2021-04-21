#include "RH_ASK.h"
#include <SPI.h>

const int ledpin = 6;

RH_ASK driver;

void setup()
{
    Serial.begin(9600);
    if(driver.init()) {
        Serial.println("Driver initialized successfully");
    } else { Serial.println("RH_ASK driver intialization error"); }
    pinMode(ledpin,INPUT);
}

void loop()
{
    int buflen = 12;
    uint8_t *buf = (uint8_t *) malloc(buflen*sizeof(uint8_t));
    if(driver.recv(buf,&buflen)) {
        digitalWrite(ledpin,HIGH);
        delay(10);
    }
}   