int min = 7;
int max = 12;
int loopMax = 64;

void setup() {
  for (int i = min; i < max + 1; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 1; i < loopMax; i = i + 1) {
    convertToBinary(i, min, max);
    delay(200);
    clear();
  }
}

void convertToBinary(int number, int pinMin, int pinMax) {
  if (pinMin > pinMax) {
    return;
  }

  int diff = (pinMax - pinMin) + 1; 
  int highestIndividaulNumber = pow(2, diff - 1);
  int highestPossibleNumber = pow(2, diff) - 1;

  if (number > highestPossibleNumber) {
    return;
  }

  int tempNumber = number;
  int nextPin = pinMax;
  int nextPinValue = highestIndividaulNumber;

  while (tempNumber > 0) {
    if (tempNumber >= nextPinValue) { // Checking if needing to turn on pin
      tempNumber = tempNumber - nextPinValue;
      digitalWrite(nextPin, HIGH);
    }

    // Setting up next pin and value
    nextPin = nextPin - 1;
    int diffTemp = nextPin - pinMin;
    nextPinValue = pow(2, diffTemp);

    if (nextPinValue % 2 != 0 && nextPinValue != 1) {
      nextPinValue = nextPinValue + 1;
    }

    if (nextPin < pinMin) {
      break;
    }
  }
}

void clear() {
  for (int i = min; i < max + 1; i++) {
    digitalWrite(i, LOW);
  }
}
