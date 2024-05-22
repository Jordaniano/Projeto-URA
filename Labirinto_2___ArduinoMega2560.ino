// estados dos botoes
int estado_buttom_esquerda = 0;
int estado_buttom_direita = 0;

// led de entrada ao labirinto
int pin_led_e = 12;

//led do final do labirinto
int pin_led_f;

// Leds dos caminhos
int pin_led_01 = 10;
int pin_led_02 = 11;
int pin_led_03 = 6;
int pin_led_04 = 7;
int pin_led_05 = 4;
int pin_led_06 = 5;
int pin_led_07 = 9;
int pin_led_08 = 8;
int pin_led_09 = 13;

//led rgb
#define PIN_VERMELHO 2
#define PIN_VERDE 3
#define PIN_AZUL 4

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


//Botões
int buttom_esquerda = 3;
int buttom_direita = 2;

//Variavel de controle de fase
int fase = 1;

void setup()
{
  pinMode(pin_led_e, OUTPUT);
  
  pinMode(pin_led_01, OUTPUT);
  pinMode(pin_led_02, OUTPUT);
  pinMode(pin_led_03, OUTPUT);
  pinMode(pin_led_04, OUTPUT);
  pinMode(pin_led_05, OUTPUT);
  pinMode(pin_led_06, OUTPUT);
  pinMode(pin_led_07, OUTPUT);
  pinMode(pin_led_08, OUTPUT);
  pinMode(pin_led_09, OUTPUT);
  //Botões
  pinMode(buttom_esquerda, INPUT);
  pinMode(buttom_direita, INPUT);
  
  digitalWrite(pin_led_e, HIGH);
  
  Serial.begin(9600);
}

void loop(){  
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  if (fase == 1){
    fase1();
  }
  delay(200);
  Serial.println(estado_buttom_esquerda);
  Serial.println(estado_buttom_direita);
  if(fase==2){
    fase2();
  }
  delay(200);
  Serial.println(estado_buttom_esquerda);
  Serial.println(estado_buttom_direita);
  if (fase == 3){
    fase3();
  }
  if(fase == 4){
    fase4();
  }
}

void fase1(){
  action_capture("vermelho");
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  digitalWrite(pin_led_01, HIGH);//Led01
  digitalWrite(pin_led_02, HIGH);//Led02
  delay(200); // Wait for 1000 millisecond(s)
  digitalWrite(pin_led_01, LOW);//Led01
  digitalWrite(pin_led_02, LOW);//Led02
  delay(200);

  if(estado_buttom_esquerda == HIGH){
    action_capture("vermelho");
    digitalWrite(pin_led_01, HIGH); //Led01(CERTO)
    Serial.println("Botão esquerdo apertado");
    Serial.println(estado_buttom_esquerda);
    fase = 2;
  }
  
  else if(estado_buttom_direita == HIGH){
    action_capture("vermelho");
    digitalWrite(pin_led_02, HIGH);//Led02(ERRADO)
    Serial.println("Botão direito apertado");
    Serial.println(estado_buttom_direita);
    fase = 2;
  }
}

void fase2(){
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  // se a pessoa foi pro caminho certo
  if(digitalRead(pin_led_01) == HIGH){  // se o Led01 está ligado
    action_capture("amarelo");
    digitalWrite(pin_led_03, HIGH);//Led03
    digitalWrite(pin_led_04, HIGH);//Led04
    delay(400);
    digitalWrite(pin_led_03, LOW);//Led03
    digitalWrite(pin_led_04, LOW);//Led04
    delay(400);
    if(estado_buttom_esquerda == HIGH){
      action_capture("amarelo");
      Serial.println("Botão esquerdo apertado");
      Serial.println(estado_buttom_esquerda);
      digitalWrite(pin_led_03, HIGH);//Led03(CERTO)
      fase = 3;
    }else if(estado_buttom_direita == HIGH){
      action_capture("vermelho");
      digitalWrite(pin_led_04, HIGH);//Led04(ERRADO)
      Serial.println("Botão direito apertado");
      Serial.println(estado_buttom_direita);
      fase = 3;
    }
  }else if(digitalRead(pin_led_02) == HIGH){
    action_capture("vermelho");
    digitalWrite(pin_led_07, HIGH);
    digitalWrite(pin_led_08, HIGH);
    delay(400);
    digitalWrite(pin_led_07, LOW);
    digitalWrite(pin_led_08, LOW);
    delay(400);
    if(estado_buttom_esquerda == HIGH){
      action_capture("vermelho");
      Serial.println("Botão esquerdo apertado");
      Serial.println(estado_buttom_esquerda);
      digitalWrite(pin_led_08, HIGH);
      fase = 3;
    }else if(estado_buttom_direita == HIGH){
      action_capture("vermelho");
      digitalWrite(pin_led_07, HIGH);
      Serial.println("Botão direito apertado");
      Serial.println(estado_buttom_direita);
      fase = 3;
    }
  }
}

void fase3(){
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  if(digitalRead(pin_led_03) == HIGH){
    action_capture("verde");
    digitalWrite(pin_led_06, HIGH);
    delay(400);
    digitalWrite(pin_led_06, LOW);
    delay(400);
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      digitalWrite(pin_led_06, HIGH);//CHEGOU AO FIM
      fase = 4;
    }
  }
  
  else if(digitalRead(pin_led_04) == HIGH){
    action_capture("vermelho");
    digitalWrite(pin_led_05, HIGH);
    delay(400);
    digitalWrite(pin_led_05, LOW);
    delay(400);
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      digitalWrite(pin_led_05, HIGH);
      fase = 4;
    }
  }
  
  else if(digitalRead(pin_led_08) == HIGH){
    action_capture("vermelho");
  	fase = 4;
  }
  
  else if(digitalRead(pin_led_07) == HIGH){
    action_capture("vermelho");
    digitalWrite(pin_led_09, HIGH);
    delay(400);
    digitalWrite(pin_led_09, LOW);
    delay(400);
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      digitalWrite(pin_led_09, HIGH);
      fase = 4;
    }
  }
}

void fase4(){
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  if(digitalRead(pin_led_06) == HIGH){
    action_capture("verde");
    digitalWrite(pin_led_f, HIGH);
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      fase = 1;
    }
  }else{
    action_capture("vermelho");
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      fase = 1;
  	}
  }
}
