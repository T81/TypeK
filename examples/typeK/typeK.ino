/*
  Type K thermocouple library example

  Author: T81

  This file is free software; you can redistribute it and/or modify
  it under the terms of either the GNU General Public License version 3
  published by the Free Software Foundation.
*/

#include <TypeK.h>
TypeK TC_K;

float Tcjc = 21.0;  // cold junction compensation temperature
float mV = 41.276;  // thermocouple mV reading
float Tsense;		// variable to store the measured temperature

void setup() {
  Serial.begin(9600);
  
  Tsense = TC_K.Temp_C(mV, Tcjc);

  Serial.print("For a measured voltage of ");
  Serial.print(mV, 3);
  Serial.println(" mV at the reference (cold) junction,");
  Serial.print("being at temperature ");
  Serial.print(Tcjc);
  Serial.println(" degC,");
  Serial.print("the measuring (hot) junction temperature is ");
  Serial.print(Tsense);
  Serial.println(" degC");
}

void loop() {
}
