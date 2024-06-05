// estados dos botoes
int estado_buttom_esquerda;
int estado_buttom_direita;

//identificar último led ligado
int x;

// led de entrada ao labirinto
int pin_led_e = 12;

//led do final do labirinto
int pin_led_f = 2;

// Leds dos caminhos
int pin_led_01 = 51;
int pin_led_02 = 13;
int pin_led_03 = 52;
int pin_led_04 = 28;
int pin_led_05 = 48;
int pin_led_06 = 53;
int pin_led_07 = 37;
int pin_led_08 = 46;
int pin_led_09 = 40;

//Botões
int buttom_esquerda = 47;
int buttom_direita = 41;

//led rgb 
#define PIN_VERMELHO 2
#define PIN_VERDE 3
#define PIN_AZUL 4

//Variavel de controle de fase
int fase = 1;

//Variavel de controle de fase 2.0
bool ffase1 = false;
bool ffase2 = false;
bool ffase3 = false;
bool ffase4 = false;

void setup() {
  pinMode(pin_led_e, OUTPUT);
  pinMode(pin_led_f, OUTPUT);

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

void loop() {
  if (ffase1 == false){
    fase = 1;
  }else if (ffase2 == false){
    fase = 2;
  }else if (ffase3 == false){
    fase = 3;
  }else if (ffase4 == false){
    fase = 4;
  }


  if (fase == 1){
    fase1();
  }
  delay(200);
  if(fase==2){
    fase2();
  }
  delay(200);
  if(fase==3){
    fase3();
  }
  delay(200);
  if(fase==4){
    fase4();
  }

}

void fase1(){
  action_capture("vermelho");
  estado_buttom_esquerda = 0;
  estado_buttom_direita = 0;

  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
  	estado_buttom_esquerda = digitalRead(47);
  	estado_buttom_direita = digitalRead(41);

    //Leitura Serial
    Serial.println("Botão esquerdo: ");
    Serial.println(estado_buttom_esquerda);
    Serial.println("Botão direito: ");
    Serial.println(estado_buttom_direita);

    //Indicando caminho disponível
    digitalWrite(pin_led_01, HIGH);//Led01
  	digitalWrite(pin_led_02, HIGH);//Led02
  	delay(400);
    digitalWrite(pin_led_01, LOW);//Led01
  	digitalWrite(pin_led_02, LOW);//Led02
  	delay(400);

  	estado_buttom_esquerda = digitalRead(47);
  	estado_buttom_direita = digitalRead(41);


  	if(estado_buttom_esquerda == HIGH){
      x = 1;
      fase = 2;
      ffase1 = true;
      fase2();
  	}else if(estado_buttom_direita == HIGH){
    	digitalWrite(pin_led_02, HIGH);//Led02(ERRADO)
      x = 2;
      fase = 2;
      ffase1 = true;
      fase2();
    }
  }
}

void fase2(){
  estado_buttom_esquerda = 0;
  estado_buttom_direita = 0;

  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
    if(x==1){ //Se a pessoa foi para o caminho certo
      action_capture("amarelo");
      estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      Serial.println("Botão esquerdo: ");
      Serial.println(estado_buttom_esquerda);
      Serial.println("Botão direito: ");
      Serial.println(estado_buttom_direita);

      digitalWrite(pin_led_03, HIGH);
      digitalWrite(pin_led_04, HIGH);
      delay(400);
      digitalWrite(pin_led_03, LOW);
      digitalWrite(pin_led_04, LOW);
      delay(400);

  	  estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

  	  if(estado_buttom_esquerda == HIGH){
        digitalWrite(pin_led_03, HIGH);
        x = 3;
        fase = 3;
        ffase2 = true;
        fase3();
  	  }else if(estado_buttom_direita == HIGH){
    	  digitalWrite(pin_led_04, HIGH);
        x = 4;
        fase = 3;
        ffase2 = true;
        fase3();
      }
    }

    else if(x==2){
      action_capture("vermelho");
      estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      Serial.println("Botão esquerdo: ");
      Serial.println(estado_buttom_esquerda);
      Serial.println("Botão direito: ");
      Serial.println(estado_buttom_direita);

      digitalWrite(pin_led_07, HIGH);
      digitalWrite(pin_led_08, HIGH);
      delay(400);
      digitalWrite(pin_led_07, LOW);
      digitalWrite(pin_led_08, LOW);
      delay(400);

  	  estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);
      if(estado_buttom_esquerda == HIGH){
        digitalWrite(pin_led_07, HIGH);
        x = 7;
        fase = 3;
        ffase2 = true;
        fase3();
      }
      else if(estado_buttom_direita == HIGH){
    	  digitalWrite(pin_led_08, HIGH);
        x = 8;
        fase = 3;
        ffase2 = true;
        fase3();
      }
    }
  }
}

void fase3 (){
  estado_buttom_esquerda = 0;
  estado_buttom_direita = 0;

  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
    if(x==3){
      action_capture("amarelo");
      estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      Serial.println("Botão esquerdo: ");
      Serial.println(estado_buttom_esquerda);
      Serial.println("Botão direito: ");
      Serial.println(estado_buttom_direita);

      digitalWrite(pin_led_06, HIGH);
      delay(400);
      digitalWrite(pin_led_06, LOW);
      delay(400);

  	  estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
        action_capture("verde");
        digitalWrite(pin_led_06, HIGH);
        digitalWrite(pin_led_f, HIGH);

        delay(800);
        x = 6;
        fase = 4;
        ffase3 = true;
        fase4();
      }
    }

    else if (x==4){
      action_capture("vermelho");
      estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      Serial.println("Botão esquerdo: ");
      Serial.println(estado_buttom_esquerda);
      Serial.println("Botão direito: ");
      Serial.println(estado_buttom_direita);

      digitalWrite(pin_led_05, HIGH);
      delay(400);
      digitalWrite(pin_led_05, LOW);
      delay(400);

  	  estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
        digitalWrite(pin_led_05, HIGH);
        x = 5;
        fase = 4;
        ffase3 = true;
        fase4();
      }
    }

    else if(x==7){
      action_capture("vermelho");
      estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      Serial.println("Botão esquerdo: ");
      Serial.println(estado_buttom_esquerda);
      Serial.println("Botão direito: ");
      Serial.println(estado_buttom_direita);

      digitalWrite(pin_led_09, HIGH);
      delay(400);
      digitalWrite(pin_led_09, LOW);
      delay(400);

  	  estado_buttom_esquerda = digitalRead(47);
  	  estado_buttom_direita = digitalRead(41);

      if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
        digitalWrite(pin_led_09, HIGH);
        x = 9;
        fase = 4;
        ffase3 = true;
        fase4();
      }
    }

    else if (x==8){
      action_capture("vermelho");
      x = 8;
      fase = 4;
      ffase3 = true;
      fase4();
    }
  }
}

void fase4(){
  estado_buttom_esquerda = 0;
  estado_buttom_direita = 0;

  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
    estado_buttom_esquerda = digitalRead(47);
  	estado_buttom_direita = digitalRead(41);

    Serial.println("Botão esquerdo: ");
    Serial.println(estado_buttom_esquerda);
    Serial.println("Botão direito: ");
    Serial.println(estado_buttom_direita);

  	estado_buttom_esquerda = digitalRead(47);
  	estado_buttom_direita = digitalRead(41);

   if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
    //Reiniciando Labirinto
    ffase1 = false;
    ffase2 = false;
    ffase3 = false;
    digitalWrite(pin_led_01, LOW);
    digitalWrite(pin_led_02, LOW);
    digitalWrite(pin_led_03, LOW);
    digitalWrite(pin_led_04, LOW);
    digitalWrite(pin_led_05, LOW);
    digitalWrite(pin_led_06, LOW);
    digitalWrite(pin_led_07, LOW);
    digitalWrite(pin_led_08, LOW);
    digitalWrite(pin_led_09, LOW);
    digitalWrite(pin_led_f, LOW);

    fase = 1;
    fase1();
   }
  }
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
   
  }else if(cor == "branco"){
    executor(PIN_VERMELHO, PIN_VERDE, PIN_AZUL, estadoLigado, estadoLigado, estadoLigado, tempoPadrao);
   
  }
  else{
    Serial.println("Cor desconhecida");
  }
}
