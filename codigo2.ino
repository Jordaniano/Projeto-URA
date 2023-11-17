//led do labirinto
int pin_led_e = 8; 
int pin_led1 = 9;
int pin_led2 = 13;
int pin_led3 = 12;
int pin_led4 = 10;
int pin_led_s = 11;
//potenciometros
int pin_pot1 = A0; 
int pin_pot2 = A1;
int potvalor1;
int potvalor2;
//led rgb
int vermelho = 7;
int verde = 6;
int azul = 5;
//Valor no monitor
int valor_nmd1;
int valor_nmd2;
//buzzer
int buzzer = 4;

void setup() {
  //monitor serial
  Serial.begin(9600);
  //led_labirinto
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_led_e, OUTPUT);
  pinMode(pin_led_s, OUTPUT);
  digitalWrite(pin_led_e, HIGH);
  //potenciometro
  pinMode(pin_pot1, INPUT);
  pinMode(pin_pot2, INPUT);
  //led_rgb
  pinMode(vermelho, OUTPUT); 
  pinMode(verde, OUTPUT); 
  pinMode(azul, OUTPUT); 
  digitalWrite(vermelho, HIGH);
  //buzzer
  pinMode(buzzer, OUTPUT);
} 

void loop() {
  digitalWrite(azul, LOW); 
  digitalWrite(verde, LOW); 
  digitalWrite(vermelho, HIGH);
  //mapeamento pot
  potvalor1 = analogRead(pin_pot1);
  potvalor2 = analogRead(pin_pot2);
  valor_nmd1 = map(potvalor1, 0, 1023, 0, 10);
  valor_nmd2 = map(potvalor2, 0, 1023, 0, 10);
  delay(1000);
 
  //LED1 & LED2
  while(digitalRead(pin_led1) == LOW) {
    //resposta certa(1 pergunta)
    digitalWrite(pin_led2, LOW);
    if(valor_nmd1 > 1 && valor_nmd1 < 5) {
      tone(buzzer, 500, 1000);
      delay(1000);
      //indicando o caminho a seguir(o caminho certo)
      if(valor_nmd2 > 8 && valor_nmd2 < 10) {
        digitalWrite(pin_led1, HIGH);
        digitalWrite(vermelho, HIGH);
        digitalWrite(verde, HIGH);
        digitalWrite(azul, LOW);
        delay(1000);
      } else if(valor_nmd2 > 4 && valor_nmd2 < 6) {
        digitalWrite(pin_led2, HIGH);
        digitalWrite(vermelho, HIGH);
        digitalWrite(verde, LOW);
        digitalWrite(azul, LOW);
        delay(1000);
      }
    } else if(valor_nmd1 > 5 && valor_nmd1 < 10) { //resposta errada(1 pergunta)
      digitalWrite(pin_led1, LOW);
      digitalWrite(azul, LOW); 
      digitalWrite(verde, LOW); 
      digitalWrite(vermelho, HIGH);
      tone(buzzer, 50, 1000);
      delay(3000);
    }
  }
Serial.println(valor_nmd1);
delay(500);
}
