#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Wire.h>
#include "SD.h"
#include "SPI.h"

//for SD
const int chipSelect = 48;
File myFile;
void log_data();
String dataMessage = "";

//***Voltage***//
//float analogInput = 35;
//float Vout = 0.00;
//float Vin = 0.00;
//float R1 = 16500.00;
//float R2 = 3300.00;
//float val = 0;

float Voltage;

//***TEMP***//
#define ONE_WIRE_BUS1 4
OneWire oneWire1(ONE_WIRE_BUS1);
DallasTemperature t1(&oneWire1);
int n1, i1;                       //??
float TEMP1[9];

#define RT0 10000  // Ω
#define B 3867      // K
#define VCC 5    //Supply voltage
#define R 10000  //R=10KΩ

float Rt1, Vr1, ln1, Tx1, T1, Vrt1;
float Rt2, Vr2, ln2, Tx2, T2, Vrt2;
float Rt3, Vr3, ln3, Tx3, T3, Vrt3;
float Rt4, Vr4, ln4, Tx4, T4, Vrt4;
float Rt5, Vr5, ln5, Tx5, T5, Vrt5;
float Rt6, Vr6, ln6, Tx6, T6, Vrt6;
//***TEMP ENDS***//

//***CURRENT***//
#define cp1 A0
#define cp2 A0

float resolution1  = 5.0 / 1024;
float resolution2  = 5.0 / 1024;
uint32_t period1 = 1000000 / 50;
uint32_t period2 = 1000000 / 50;
uint32_t t_start1 = 0;
uint32_t t_start2 = 0;

// for setup
float zero_ADC_Value1 = 0;
float zero_ADC_Value2 = 0;
float zero_voltageValue1 = 0;
float zero_voltageValue2 = 0;

// for loop
float ADC1 = 0;
float ADC2 = 0;
float Vrms1 = 0;
float Vrms2 = 0;
float Current1 = 0;
float Current2 = 0;
float Q1 = 0.0147;
float Q2 = 0.0147;
float sensitivity1 = 0.11;
float sensitivity2 = 0.11;

//***Accelerometer***//
int MPU = 0x68;
double ACCX, ACCY, ACCZ;
double GYROX, GYROY, GYROZ;
float AccAngleX, AccAngleY;
float GyroX, GyroY, GyroZ;
double roll, pitch;
float preTime, currentTime, timeDiff;

//***Speed**//
float rpmfloat;
#define Hall 2
unsigned long rpmtime;
bool tooslow = 1;

void log_data();

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200); 
  T1 = 25 + 273.15;
  T2 = 25 + 273.15;
  T3 = 25 + 273.15;
  T4 = 25 + 273.15;
  T5 = 25 + 273.15;
  T6 = 25 + 273.15;
  Current_setup();

  //***SD***//
  init_sdcard();
  acc_setup();

}

void loop()
{
  Current_loop();
  temp();
  Voltage = getVPP();
  acc_loop();
}

void log_data(void)
{
  myFile = SD.open("EXAMPLE.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("open with success");
    //dataMessage =
      //(String(millis()) + "," + String(Current1) + "," + String(Current2) + "," + String(volt) + "," +  String(rpmfloat) + "," + String(Tx1)+ "," + String(Tx2) + "\r\n");
//    Serial2.println(dataMessage);        //for HC05 app
    myFile.print(dataMessage);
    Serial.println(dataMessage);
  }
  myFile.close();
  dataMessage = "";
}
