int pirPin = 8;  // PIR sensor pin
int ledPin = 9;  // LED pin

void setup() {
  pinMode(pirPin, INPUT);  // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Start serial communication
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {  // If motion is detected
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Motion detected");  // Print to Serial Monitor
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    Serial.println("No motion");  // Print to Serial Monitor
  }
  delay(500);  // Small delay for readability
}
