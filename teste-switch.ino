//led do labirinto
int pin_led_e = 12; 
int pin_led1 = 11;
int pin_led2 = 6;
int pin_led3 = 7;
int pin_led4 = 10;
int pin_led_s = 8;
//potenciometros
int pin_pot1 = A2; 
int pin_pot2 = A1;
int potvalor1;
int potvalor2;
//led rgb
#define PIN_VERMELHO 2
#define PIN_VERDE 3
#define PIN_AZUL 4
//Valor no monitor
int valor_nmd1;
int valor_nmd2;

//Controle do código
int y = 0

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
  
} 

void executor(int pinVermelho, int pinVerde, int pinAzul, int estadoR, int estadoG, int estadoB, int tempo) {
  digitalWrite(pinVermelho, estadoR);
  digitalWrite(pinVerde, estadoG);
  digitalWrite(pinAzul, estadoB);
  delay(tempo);
}

void action_capture(String cor) {
  int tempoPadrao = 0;  // Tempo padrão para cada estado (1 segundo)
  int estadoDesligado = 1;
  int estadoLigado = 0;
  
  if (cor == "vermelho") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoLigado, estadoDesligado, estadoDesligado, tempoPadrao);

  } else if (cor == "verde") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoLigado, estadoDesligado, tempoPadrao);
   
  } else if (cor == "azul") {
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoDesligado, estadoDesligado, estadoLigado, tempoPadrao);
    
  } else if(cor == "amarelo"){
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoLigado, estadoLigado, estadoDesligado, tempoPadrao);
   
  }else{
    Serial.println("Cor desconhecida");
  }
}

void loop(){
  
  //mapeamento pot
  potvalor1 = analogRead(pin_pot1);
  potvalor2 = analogRead(pin_pot2);
  valor_nmd1 = map(potvalor1, 0, 1023, 0, 10);
  valor_nmd2 = map(potvalor2, 0, 1023, 0, 10);
  delay(1000);
  Serial.println(valor_nmd2);
  delay(500);

  //Controle do switch case
  if(valor_nmd1>1 && valor_nmd1<5 && digitalRead(pin_led1) == 1){
    y = 1
  }else if(valor_nmd2>1 && valor_nmd2<5 && digitalRead(pin_led1) == 1 && digitalRead(pin_led3) == 1){
  	y = 2
  }else{
  	y = 0
  }
  
  switch(y){
    case 0:
  		action_capture("vermelho");
  		if (valor_nmd1==0){
    		digitalWrite(pin_led1, LOW);
    		digitalWrite(pin_led3, LOW);
    		digitalWrite(pin_led_s, LOW);
  		} 
    
    	//resposta certa(1 pergunta)
   		else if(valor_nmd1>1 && valor_nmd1<5){
    		digitalWrite(pin_led1, HIGH);
    		digitalWrite(pin_led2, LOW);
    		action_capture("amarelo");
          	y = 1
  		}
    	//resposta errada(1 pergunta)
    	else if(valor_nmd1>5 && valor_nmd1<10){
    		digitalWrite(pin_led1,LOW);
    		digitalWrite(pin_led2, HIGH);
    		action_capture("vermelho");
  		}
 	case 1:
  		if(valor_nmd2 == 0){
    		digitalWrite(pin_led3, LOW);
    		digitalWrite(pin_led4, LOW);
  		}//resposta certa(2 pergunta)
  		if(valor_nmd2>1 && valor_nmd2<5 && digitalRead(pin_led1) == 1){
    		digitalWrite(pin_led3, HIGH);
    		digitalWrite(pin_led4, LOW);
    		action_capture("verde");
          	y = 2
    
 		}else if(valor_nmd2>5 && valor_nmd2<10){ //resposta errada(2 pergunta)
    		digitalWrite(pin_led3,LOW);
  			action_capture("amarelo");
    		digitalWrite(pin_led4, HIGH);
  		}
  	case 2:
  		if(digitalRead(pin_led1) == 1 && digitalRead(pin_led3) == 1){
    		digitalWrite(pin_led_s, HIGH);
    		action_capture("verde");    
  		}else{
    		digitalWrite(pin_led_s, LOW);
  		}
}
