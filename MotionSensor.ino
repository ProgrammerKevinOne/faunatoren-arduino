int motionSensorPin = 3; // DIO pin connected to pin 3
int motionState = LOW;   // Variable to store the sensor state

void SetupMotionSensor() {
  pinMode(motionSensorPin, INPUT); // Set pin as input
}

void LoopMotionSensor() {
  motionState = digitalRead(motionSensorPin); // Read the sensor state
  
  if (motionState == HIGH) {
    Serial.println("Motion detected!");
    // Add any other actions here (e.g., turn on an LED)
  } else {
    Serial.println("No motion.");
  }
  
  delay(500); // Wait for half a second before checking again
}
