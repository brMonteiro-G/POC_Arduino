#define RED_LED_PIN 2
#define GREEN_LED_PIN 3
#define YELLOW_LED_PIN 4
#define RED_LED_BUTTON 10
#define YELLOW_LED_BUTTON 11
#define GREEN_LED_BUTTON 12
#define LENGTH_OF_LED_lIST 3
#define SECOND 1000
#define HALF_SECOND 500


int ledList[LENGTH_OF_LED_lIST];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initializePorts();
  startGame();
}

void initializePorts() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_BUTTON, INPUT_PULLUP);
  pinMode(YELLOW_LED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_LED_BUTTON, INPUT_PULLUP);


}

void startGame() {
  int potentiometer = analogRead(0);
  Serial.println(potentiometer);
  randomSeed(potentiometer);
  for (int index = 0; index < LENGTH_OF_LED_lIST ; index++) {
    ledList[index] = sortColor();
  }


} 

int sortColor() {
  // random(n1,n2) intervalo aberto no número n2
  return random(RED_LED_PIN, YELLOW_LED_PIN + 1);
}

void loop() {
  // put your main code here, to run repeatedly:

    for(int index = 0; index< LENGTH_OF_LED_lIST; index++){
    flashesLed(ledList[index]);
    }
  //  int redButtonState = digitalRead(RED_LED_BUTTON);


  checkPlayerResponse();
  startGame();

}


void checkPlayerResponse() {
  if (digitalRead(RED_LED_BUTTON) == LOW) {
    return flashesLed(RED_LED_PIN);
  }
  if (digitalRead(GREEN_LED_BUTTON) == LOW) {
    return flashesLed(GREEN_LED_PIN);
  }
  if (digitalRead(YELLOW_LED_BUTTON) == LOW) {
    return flashesLed(YELLOW_LED_PIN);
  }

}
void flashesLed(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(SECOND);
  digitalWrite(ledPin, LOW);
  delay(HALF_SECOND);
}

void flashesAllLeds() {
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(YELLOW_LED_PIN, HIGH);

  delay(SECOND);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);

  delay(HALF_SECOND);
}
