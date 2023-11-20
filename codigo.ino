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
#define PIN_VERMELHO 9
#define PIN_VERDE 10
#define PIN_AZUL 11
//Valor no monitor
int valor_nmd1;
int valor_nmd2;
//buzzer
int buzzer = 4;


void setup(){
  //monitor serial
  Serial.begin (9600);
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
  pinMode (PIN_VERMELHO, OUTPUT); 
  pinMode (PIN_VERDE, OUTPUT); 
  pinMode (PIN_AZUL, OUTPUT);
  //buzzer
  pinMode(buzzer, OUTPUT);
} 

void executor(int pinVermelho, int pinVerde, int pinAzul, int estadoR, int estadoG, int estadoB, int tempo) {
  digitalWrite(pinVermelho, estadoR);
  digitalWrite(pinVerde, estadoG);
  digitalWrite(pinAzul, estadoB);
  delay(tempo);
}

void action_capture(String cor) {
  int tempoPadrao = 1000;  // Tempo padrão para cada estado (1 segundo)
  int estadoDesligado = 0;
  int estadoLigado = 1;
  
  if (cor == "vermelho") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoLigado, estadoDesligado, estadoDesligado, tempoPadrao);
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoDesligado, estadoDesligado, tempoPadrao);
  } else if (cor == "verde") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoLigado, estadoDesligado, tempoPadrao);
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoDesligado, estadoDesligado, tempoPadrao);
  } else if (cor == "azul") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoDesligado, estadoLigado, tempoPadrao);
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoDesligado, estadoDesligado, tempoPadrao);
  } else if(cor == "amarelo"){
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoLigado, estadoLigado, estadoDesligado, tempoPadrao);
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado,estadoDesligado, estadoDesligado, tempoPadrao);
  }else{
    Serial.println("Cor desconhecida");
  }
}

void loop(){
  
  //mapeamento pot
  action_capture("vermelho");
  potvalor1 = analogRead(pin_pot1);
  potvalor2 = analogRead(pin_pot2);
  valor_nmd1 = map(potvalor1, 0, 1023, 0, 10);
  valor_nmd2 = map(potvalor2, 0, 1023, 0, 10);
  delay(1000);
  Serial.println(valor_nmd1);
  delay(500);
  
  //resposta certa(1 pergunta)
  if(valor_nmd1>1 && valor_nmd1<5){
   	digitalWrite(pin_led1, HIGH);
   	digitalWrite(pin_led2, LOW);
    action_capture("amarelo");
  	delay(2000);
 }else if(valor_nmd1>5 && valor_nmd1<10){ //resposta errada(1 pergunta)
  	digitalWrite(pin_led1,LOW);
  	digitalWrite(pin_led2, HIGH);
    action_capture("vermelho");
  	delay(2000);
  	tone(buzzer,50, 1000);
  	delay(5000);
  }
    //resposta certa(2 pergunta)
  if(valor_nmd2>1 && valor_nmd2<5 && digitalRead(pin_led1) == 1){
   	digitalWrite(pin_led3, HIGH);
   	digitalWrite(pin_led4, LOW);
	action_capture("verde");
  	delay(2000);
 }else if(valor_nmd2>5 && valor_nmd2<10){ //resposta errada(2 pergunta)
  	digitalWrite(pin_led3,LOW);
	action_capture("amarelo");
  	digitalWrite(pin_led4, HIGH);
  	delay(2000);
  	tone(buzzer,50, 1000);
  	delay(5000);
  }
  if(digitalRead(pin_led1) == 1 && digitalRead(pin_led3) == 1){
    digitalWrite(pin_led_s, HIGH);
  	action_capture("verde");    
  }
}
