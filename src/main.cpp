#define DEBUG             1

#define BUTTON_PIN        19
#define LED_PIN           18
#define DEBOUNCE_DELAY    100

#include <Arduino.h>

uint32_t lastDebounceTime = 0;


void setup() {  
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (millis() - lastDebounceTime < DEBOUNCE_DELAY) {
    return;
  }
  lastDebounceTime = millis();
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}