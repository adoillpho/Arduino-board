#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int lightRelayPin = 2; // Connect the light relay to digital pin 2
const int fanRelayPin = 3;   // Connect the fan relay to digital pin 3
const int microphonePin = A0; // Connect the microphone sensor to analog pin A0

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(lightRelayPin, OUTPUT);
  pinMode(fanRelayPin, OUTPUT);

  // Initialize the relays to OFF
  digitalWrite(lightRelayPin, LOW);
  digitalWrite(fanRelayPin, LOW);
}

void loop() {
  if (mySerial.available()) {
    String voiceCommand = mySerial.readStringUntil('\n');
    voiceCommand.trim();
    
    if (voiceCommand == "light on") {
      digitalWrite(lightRelayPin, HIGH); // Turn on the light
      Serial.println("Light is ON");
    } else if (voiceCommand == "light off") {
      digitalWrite(lightRelayPin, LOW); // Turn off the light
      Serial.println("Light is OFF");
    } else if (voiceCommand == "fan on") {
      digitalWrite(fanRelayPin, HIGH); // Turn on the fan
      Serial.println("Fan is ON");
    } else if (voiceCommand == "fan off") {
      digitalWrite(fanRelayPin, LOW); // Turn off the fan
      Serial.println("Fan is OFF");
    }
  }

  // You can add more voice commands and functionalities here
}
