float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 1024;          // store min value here ESP32 ADC resolution

  uint32_t start_time = millis();
  while ((millis() - start_time) < 500) 
  {
//    readValue = analogRead(sensorIn);
  }
  result = ((readValue) * 5) / 1024;

  return result;
}
