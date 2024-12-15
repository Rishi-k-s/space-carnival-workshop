// Pin configuration
const int rainDigitalPin = 9; // Digital pin connected to DO on the rain sensor
const int ledPin = 8;        // LED pin to indicate rain detection

void setup() {
  pinMode(rainDigitalPin, INPUT); // Configure rain sensor digital pin as input
  pinMode(ledPin, OUTPUT);        // Configure LED pin as output
  Serial.begin(9600);             // Initialize Serial Monitor
}

void loop() {
  // Read the rain sensor digital output
  int rainStatus = digitalRead(rainDigitalPin);

  // Check if rain is detected
  if (!rainStatus) { // Inverted logic (rain detected when rainStatus is 0)
    Serial.println("Rain detected!");
    digitalWrite(ledPin, HIGH); // Turn on LED if raining
  } else {
    Serial.println("No rain detected.");
    digitalWrite(ledPin, LOW);  // Turn off LED if not raining
  }

  delay(1000); // Delay for 1 second
}
