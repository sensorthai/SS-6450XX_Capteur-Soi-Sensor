//#include <ESP8266WiFi.h>//ใช้กับบอร์ดesp8266
#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <Arduino.h>

Adafruit_ADS1115 ads1115(0x48); // construct an ads1115 at address 0x49
float Voltage0 = 0.0;
float Voltage1 = 0.0;
float Voltage2 = 0.0;
float Voltage3 = 0.0;
float soil1 = 0.0;
float soil2 = 0.0;
float soil3 = 0.0;
float soil4 = 0.0;
float tempsoil1 = 0.0;
float tempsoil2 = 0.0;
float tempsoil3 = 0.0;
float tempsoil4 = 0.0;

void setup() {
 Serial.begin(9600);
 ads1115.begin();  // Initialize ads1115
 Wire.begin();
 delay(500);
}

void loop() 
{

int16_t adc0, adc1, adc2, adc3;
 
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc2 = ads1115.readADC_SingleEnded(2);
  adc3 = ads1115.readADC_SingleEnded(3);
  float Voltage1 = (adc0 * 0.1875)/1000;
  float Voltage2 = (adc1 * 0.1875)/1000;
  float Voltage3 = (adc2 * 0.1875)/1000;
  float Voltage4 = (adc3 * 0.1875)/1000;
  
  soil1 =(Voltage1-2.1)/(-0.018);
  if (soil1 >= 100)
{
  soil1 = 100; // Soil sat
}
else
{
soil1 = abs(soil1);
}

 Serial.print("soil1 (%) = "); Serial.println(soil1);
//................................................................................................ 
 tempsoil1 =(Voltage2-0.5)/0.010;
 
 Serial.print("tempsoil1 (C) = "); Serial.println(tempsoil1);

 
delay(500);
}
