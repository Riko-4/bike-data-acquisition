void temp()
{
//****Temp 1***//
  Vrt1 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt1 = (5.0 / 1023.00) * Vrt1;      //Conversion to voltage
  //Serial.println(Vrt1);
  Vr1 = VCC - Vrt1;
  Rt1 = Vrt1 / (Vr1 / R);               //Resistance of RT
  //Serial.println(Rt1);

  ln1 = log(Rt1 / RT0);
  Tx1 = (1 / ((ln1 / B) + (1 / T1))); //Temperature from thermistor

  Tx1 = Tx1 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx1);

//****Temp 2***//
  Vrt2 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt2 = (5.0 / 1023.00) * Vrt2;      //Conversion to voltage
  //Serial.println(Vrt1);
  Vr2 = VCC - Vrt2;
  Rt2 = Vrt2 / (Vr2 / R);               //Resistance of RT
  //Serial.println(Rt2);

  ln2 = log(Rt2 / RT0);
  Tx2 = (1 / ((ln2 / B) + (1 / T2))); //Temperature from thermistor

  Tx2 = Tx2 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx2);

//****Temp 3***//
  Vrt3 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt3 = (5.0 / 1023.00) * Vrt3;      //Conversion to voltage
  //Serial.println(Vrt3);
  Vr3 = VCC - Vrt3;
  Rt3 = Vrt3 / (Vr3 / R);               //Resistance of RT
  //Serial.println(Rt3);

  ln3 = log(Rt3 / RT0);
  Tx3 = (1 / ((ln3 / B) + (1 / T3))); //Temperature from thermistor

  Tx3 = Tx3 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx3);

//***Temp4***//
  Vrt4 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt4 = (5.0 / 1023.00) * Vrt4;      //Conversion to voltage
  //Serial.println(Vrt4);
  Vr4 = VCC - Vrt4;
  Rt4 = Vrt4 / (Vr4 / R);               //Resistance of RT
  //Serial.println(Rt4);

  ln4 = log(Rt4 / RT0);
  Tx4 = (1 / ((ln4 / B) + (1 / T4))); //Temperature from thermistor

  Tx4 = Tx4 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx4);

//***Temp5***//
Vrt5 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt5 = (5.0 / 1023.00) * Vrt5;      //Conversion to voltage
  //Serial.println(Vrt5);
  Vr5 = VCC - Vrt5;
  Rt5 = Vrt5 / (Vr5 / R);               //Resistance of RT
  //Serial.println(Rt5);

  ln5 = log(Rt5 / RT0);
  Tx5 = (1 / ((ln5 / B) + (1 / T5))); //Temperature from thermistor

  Tx5 = Tx5 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx5);

//***Temp6***//
Vrt6 = analogRead(A3);              //Acquisition analog value of VRT
  Vrt6 = (5.0 / 1023.00) * Vrt6;      //Conversion to voltage
  //Serial.println(Vrt6);
  Vr6 = VCC - Vrt6;
  Rt6 = Vrt6 / (Vr6 / R);               //Resistance of RT
  //Serial.println(Rt6);

  ln6 = log(Rt6 / RT0);
  Tx6 = (1 / ((ln6 / B) + (1 / T6))); //Temperature from thermistor

  Tx6 = Tx6 - 273.15;                 //Conversion to Celsius
  // Serial.println(Tx6);
}
