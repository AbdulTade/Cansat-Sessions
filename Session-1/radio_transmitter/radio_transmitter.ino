#include "RH_ASK.h"
#include <SPI.h>

const int button = 4;

RH_ASK driver;

void setup()
{
    Serial.begin(9600);
    if(driver.init())
    {
        Serial.println("Driver initialized successfully");
    } else {Serial.println("RH_ASK driver initialization error")}
    pinMode(button,HIGH);
}

void loop()
{
    const char *msg = "1";
    if(digitalRead(button) == HIGH){
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(10);
    }
    
}