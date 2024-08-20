#define DEBUG             1

#define BUTTON_PIN        19
#define LED_PIN           18
#define DEBOUNCE_DELAY    100

#include <Arduino.h>

uint32_t lastDebounceTime = 0;

void buttonRead(){
  if (millis() - lastDebounceTime < DEBOUNCE_DELAY) {
    return;
  }
  lastDebounceTime = millis();
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (DEBUG) Serial.println("Button pressed");
    digitalWrite(LED_PIN, HIGH);
    if (DEBUG) Serial.println("LED on");
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    if (DEBUG) Serial.println("LED off");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() {  
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonRead();
}