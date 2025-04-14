const byte LED_A = 4;
const byte LED_B = 3;
const byte LED_C = 2;
const byte LED_D = 1;

byte randomNum = 0;

void setup() {
  randomSeed(analogRead(A0));
  randomNum = random(1, 4);
  switch (randomNum) {
    case 1:
      loopLeds(false);
      break;
    case 2:
      loopLeds(true);
      break;
    case 3:
      flashLeds();
      break;
  }
  resetPins();
}

void loop() {
  
}

void resetPins() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
  pinMode(LED_D, INPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
  digitalWrite(LED_D, LOW);
}

void setPins(int high_pin, int low_pin) {
  resetPins();
  pinMode(high_pin, OUTPUT);
  pinMode(low_pin, OUTPUT);
  digitalWrite(high_pin, HIGH);
  digitalWrite(low_pin, LOW);
}

void loopLeds(bool reversed) {
  if (reversed) {
    for (int i = 12; i >= 1; i--) {
      lightLed(i);
      delay(100);
    }
  } else {
    for (int i = 1; i <= 12; i++) {
      lightLed(i);
      delay(100);
    }
  }
}

void flashLeds() {
  for (int i = 0; i < 30; i++) {
    for (int j = 1; j <= 12; j++) {
      lightLed(j);
      delay(5);
    }
  }
}

void lightLed(int led_num) {
  switch (led_num) {
    case 1: setPins(LED_B, LED_A); break;
    case 2: setPins(LED_A, LED_B); break;
    case 3: setPins(LED_C, LED_B); break;
    case 4: setPins(LED_B, LED_C); break;
    case 5: setPins(LED_D, LED_C); break;
    case 6: setPins(LED_C, LED_D); break;
    case 7: setPins(LED_C, LED_A); break;
    case 8: setPins(LED_A, LED_C); break;
    case 9: setPins(LED_D, LED_B); break;
    case 10: setPins(LED_B, LED_D); break;
    case 11: setPins(LED_D, LED_A); break;
    case 12: setPins(LED_A, LED_D); break;
  }
}
