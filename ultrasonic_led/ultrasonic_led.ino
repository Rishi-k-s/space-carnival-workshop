#define trigPin 8    // Trigger pin for ultrasonic sensor
#define echoPin 7    // Echo pin for ultrasonic sensor
#define ledPin 9     // LED pin

void setup() {
  pinMode(trigPin, OUTPUT);  // Set Trigger pin as OUTPUT
  pinMode(echoPin, INPUT);   // Set Echo pin as INPUT
  pinMode(ledPin, OUTPUT);   // Set LED pin as OUTPUT
  Serial.begin(9600);        // Initialize serial communication
}

void loop() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);      

  digitalWrite(trigPin, HIGH);  // Send pulse to trigger
  delayMicroseconds(10);       
  digitalWrite(trigPin, LOW);  

  long duration = pulseIn(echoPin, HIGH);  // Measure pulse duration
  int distance = duration * 0.0344 / 2;    // Calculate distance

  Serial.print("Distance: ");
  Serial.println(distance);  // Display distance in Serial Monitor

  if (distance < 20) {   // If object is closer than 20 cm
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  delay(500);  // Short delay
}
