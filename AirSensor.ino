#include <Wire.h>
#include "Adafruit_AM2315.h"

// Maak een AM2315 object
Adafruit_AM2315 am2315;

void SetupAirSensor() {
  
  
  // Start de AM2315
  if (!am2315.begin()) {
    Serial.println("Kon de AM2315 niet vinden, check de verbindingen!");
    while (1);
  }
  Serial.println("AM2315 sensor gevonden.");
}

void LoopAirSensor() {
  // Lees de temperatuur en vochtigheid
  float temperature = am2315.readTemperature();
  float humidity = am2315.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperatuur: ");
    Serial.print(temperature);
    Serial.println(" *C");
    
    Serial.print("Vochtigheid: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Kon data niet lezen!");
  }

  delay(2000); // Wacht 2 seconden tussen metingen
}