//Use digital IO pins 2 to 12.
//0 and 1 are used by the serial port. 13 is used for an LED.
#define PINLIST_LOW  2
#define PINLIST_HIGH  12
#define DEBOUNCETIME_MILLISECONDS  10

int currentState[PINLIST_HIGH +1];
unsigned long timeOfLastStateChange[PINLIST_HIGH +1];

int state = HIGH;

void setup() {
  Serial.begin(115200);
  for (byte pin = PINLIST_LOW; pin <= PINLIST_HIGH; pin = pin + 1) {
    pinMode(pin, INPUT_PULLUP);
    currentState[pin] = digitalRead(pin);
    timeOfLastStateChange[pin] = millis()-DEBOUNCETIME_MILLISECONDS;
  }
}

void loop() {
  for (byte pin = PINLIST_LOW; pin <= PINLIST_HIGH; pin = pin + 1) {
    state = digitalRead(pin);
    if (millis() - timeOfLastStateChange[pin] >= (unsigned long)DEBOUNCETIME_MILLISECONDS){
      if (state != currentState[pin]) {
        currentState[pin] = state;
        Serial.println(String(pin) + ":" + String(currentState[pin]));
        timeOfLastStateChange[pin] = millis();
      }   
    }
  }
}


