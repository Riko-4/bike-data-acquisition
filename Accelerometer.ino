void acc_setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true); 
}

void acc_loop()
{
  Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU, 6, true);
ACCX= (Wire.read()<<8|Wire.read())/16384.00;
ACCY= (Wire.read()<<8|Wire.read())/16384.00;
ACCZ= (Wire.read()<<8|Wire.read())/16384.00;

//time for gyro
preTime=currentTime;
currentTime=millis();
timeDiff=(currentTime-preTime)/1000.00;

//Gyro in degree/s
Wire.beginTransmission(MPU);
Wire.write(0x43);
Wire.endTransmission(false);
Wire.requestFrom(MPU, 6, true);
GYROX=(Wire.read()<<8|Wire.read())/131.00;
GYROY=(Wire.read()<<8|Wire.read())/131.00;
GYROZ=(Wire.read()<<8|Wire.read())/131.00;

//AngleX and AngleY for pitch and roll
AccAngleX=atan(ACCY/sqrt(pow(ACCX,2)+pow(ACCZ,2)))*180/PI;
AccAngleY=atan((-1*ACCX)/sqrt(pow(ACCY,2)+pow(ACCZ,2)))*180/PI;

//Gyro in degrees
GyroX= GYROX*timeDiff+ GyroX;
GyroY= GYROY*timeDiff+ GyroY;
GyroZ= GYROZ*timeDiff+ GyroZ;

//roll and pitch
roll= 0.96*GyroX+0.04*AccAngleX;
pitch= 0.96*GyroY+0.04*AccAngleY;

//Serial.println((String)"Acceleration of on X axis:"+ACCX);
//Serial.println((String)"Acceleration of on Y axis:"+ACCY);
//Serial.println((String)"Acceleration of on Z axis:"+ACCZ);
//Serial.println((String)"Roll:"+roll);
//Serial.println((String)"Pitch:"+pitch);
}
