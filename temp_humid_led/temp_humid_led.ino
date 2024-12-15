#include <DHT.h>

// Pin configuration
#define DHTPIN 8      // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11 // DHT 11 sensor type
const int ledPin = 9; // LED pin

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

void setup() {
  pinMode(ledPin, OUTPUT); // Configure LED pin as output
  Serial.begin(9600);      // Initialize Serial Monitor
  dht.begin();             // Start the DHT sensor
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();       // Read humidity

  // // Check if the readings are valid
  // if (isnan(temperature) || isnan(humidity)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   return;
  // }

  // Display temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Control the LED based on temperature
  if (temperature < 25) {
    digitalWrite(ledPin, HIGH); // Turn on LED if temperature is below 25°C
    Serial.println("Temperature is below 25°C. LED is ON.");
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED otherwise
    Serial.println("Temperature is 25°C or above. LED is OFF.");
  }

  delay(2000); // Wait for 2 seconds before reading again
}
