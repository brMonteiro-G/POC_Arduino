#define LED_VERMELHO 12 
#define BOTAO_VERMELHO 10 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BOTAO_VERMELHO, INPUT_PULLUP);

  digitalWrite(LED_VERMELHO, HIGH);
  delay(1000);
  digitalWrite(LED_VERMELHO, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int estadoBotao = digitalRead(BOTAO_VERMELHO);
  Serial.println(estadoBotao);
  delay(500);
}
