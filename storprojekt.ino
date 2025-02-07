

// Import libraries
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

int motorPin = 5;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
  if (!accel.begin()) {
    Serial.println("No ADXL345 detected. Check wiring!");
    while (1);
  }
  Serial.println("ADXL345 initialized.");
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  // Print the acceleration values
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print(" m/s^2, Y: ");
  Serial.print(event.acceleration.y);
  Serial.print(" m/s^2, Z: ");
  Serial.print(event.acceleration.z);
  Serial.println(" m/s^2");

  // Motor control logic
  if (event.acceleration.z < -5 || event.acceleration.x > 4 || event.acceleration.x < -4) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  delay(100); // Delay for readability and motor control stability
}