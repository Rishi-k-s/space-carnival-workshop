#define IR_SENSOR_PIN 8  // Pin connected to the IR sensor
#define LED_PIN_9 9      // Pin connected to the first LED (obstacle detected)
#define LED_PIN_10 10    // Pin connected to the second LED (no obstacle detected)

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);  // Set IR sensor pin as input
  pinMode(LED_PIN_9, OUTPUT);     // Set LED pin 9 as output
  pinMode(LED_PIN_10, OUTPUT);    // Set LED pin 10 as output
  Serial.begin(9600);             // Start serial communication at 9600 baud
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN); // Read the state of the IR sensor

  if (sensorValue == LOW) { // IR sensor detects an obstacle
    digitalWrite(LED_PIN_9, HIGH); // Turn on the LED connected to pin 9
    digitalWrite(LED_PIN_10, LOW); // Turn off the LED connected to pin 10
    Serial.println("Obstacle detected! LED on pin 9 ON.");
  } else { // No obstacle detected
    digitalWrite(LED_PIN_9, LOW);  // Turn off the LED connected to pin 9
    digitalWrite(LED_PIN_10, HIGH); // Turn on the LED connected to pin 10
    Serial.println("No obstacle detected. LED on pin 10 ON.");
  }

  delay(500); // Small delay to make Serial Monitor output more readable
}
