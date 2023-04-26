// Define moisture sensor pins
const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;

// Define relay control pin
const int relayPin = 2;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set relay control pin as output
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Read moisture sensor values
  int moisture1 = analogRead(sensorPin1);
  int moisture2 = analogRead(sensorPin2);
  int moisture3 = analogRead(sensorPin3);

  // Check if moisture is dry
  if (moisture1 < 500 && moisture2 < 500 && moisture3 < 500) {
    // Turn on relay to activate motor
    digitalWrite(relayPin, LOW);

    // Print status to serial monitor
    Serial.println("Field is WET. Motor deactivated.");
  } 
  // Check if moisture is wet
  else {
    // Turn off relay to deactivate motor
    digitalWrite(relayPin, HIGH);

    // Print status to serial monitor
    Serial.println("Field is DRY. Motor activated.");
  }

  // Wait for 1 second before taking another reading
  delay(3000);
}