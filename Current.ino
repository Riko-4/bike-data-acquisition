void Current_setup()
{
  pinMode(cp1, INPUT);
  t_start1 = micros();
  uint32_t ADC_SUM1 = 0, n1 = 0;
  while (micros() - t_start1 < period1)
  {
    ADC_SUM1 += analogRead(cp1);                   // reading the analog value from pin A0.
    n1++;                                          // counter to be used for avg.
  }
  zero_ADC_Value1 = (ADC_SUM1 / n1);                 // The avg analog value when no current pass throught the ACS712 sensor.
  zero_voltageValue1 = zero_ADC_Value1 * resolution1;


  pinMode(cp2, INPUT);
  t_start2 = micros();
  uint32_t ADC_SUM2 = 0, n2 = 0;
  while (micros() - t_start2 < period2)
  {
    ADC_SUM2 += analogRead(cp2);
    n2++;
  }
  zero_ADC_Value2 = (ADC_SUM2 / n2);                 // The avg analog value when no current pass throught the ACS712 sensor.
  zero_voltageValue2 = zero_ADC_Value2 * resolution2;
}
void Current_loop()
{
  t_start1 = micros();
  uint32_t ADC_Dif1 = 0, ADC_SUM1 = 0, m1 = 0;
  while (micros() - t_start1 < period1)
  {
    ADC_Dif1 = zero_ADC_Value1 - analogRead(cp1);
    ADC_SUM1 += ADC_Dif1 * ADC_Dif1;
    m1++;
  }
  ADC1 = sqrt(ADC_SUM1 / m1);                        // The root-mean-square ADC value.
  Vrms1 = ADC1 * resolution1;                       // The root-mean-square analog voltage value.
  Current1 = (Vrms1  / sensitivity1) - Q1;

  t_start2 = micros();
  uint32_t ADC_Dif2 = 0, ADC_SUM2 = 0, m2 = 0;
  while (micros() - t_start2 < period2)
  {
    ADC_Dif2 = zero_ADC_Value2 - analogRead(cp2);
    ADC_SUM2 += ADC_Dif2 * ADC_Dif2;
    m2++;
  }
  ADC2 = sqrt(ADC_SUM2 / m2);
  Vrms2 = ADC2 * resolution2;
  Current2 = (Vrms2  / sensitivity2) - Q2;
}
