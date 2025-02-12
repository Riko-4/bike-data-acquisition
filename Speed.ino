void rpm()
{
  Serial.println("rpm");
  pinMode(Hall, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(Hall), RPM_int, FALLING);
  for (;;) 
  {
    //Serial.println(analogRead(Hall));

    rpmfloat = (120 / (rpmtime / 31250.00) * 0.110081);
    // rpm = round(rpmfloat);

    if (tooslow == 1) 
    {
      rpmfloat = 0;
    }
  }
}

void RPM_int() 
{
  rpmtime = TCNT4;
  TCNT4 = 0;//Reset Timer 1 and set comp value
  tooslow = 0;
}
