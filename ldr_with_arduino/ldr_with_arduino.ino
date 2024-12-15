int ldrPin = 8;  // LDR sensor pin (digital)
int ledPin = 9;   // LED pin
int ldrValue = 0; // Variable to store LDR sensor value

void setup() {
  pinMode(ldrPin, INPUT);  // Set LDR pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  ldrValue = digitalRead(ldrPin);  // Read digital LDR value (HIGH or LOW)
  
  // Print the LDR value to the Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // If the LDR value is LOW (dark), turn ON the LED
  if (ldrValue == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }
  
  delay(100);  // Small delay for stability
}
