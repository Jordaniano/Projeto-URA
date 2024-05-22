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
  }if(fase== 4){
  	fase4();
  }

}

void fase1(){
  //CASO O LABIRINTO REINICIE > DESLIGAR LEDS
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
  
  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
  	estado_buttom_esquerda = digitalRead(3);
  	estado_buttom_direita = digitalRead(2);
    Serial.println("Botão esquerdo: ");
    Serial.println(estado_buttom_esquerda);
    Serial.println("Botão direito: ");
    Serial.println(estado_buttom_direita);
  	digitalWrite(pin_led_01, HIGH);//Led01
  	digitalWrite(pin_led_02, HIGH);//Led02
  	delay(400);
  	digitalWrite(pin_led_01, LOW);//Led01
  	digitalWrite(pin_led_02, LOW);//Led02
  	delay(400);
  	estado_buttom_esquerda = digitalRead(3);
  	estado_buttom_direita = digitalRead(2);
  	if(estado_buttom_esquerda == HIGH){
    	digitalWrite(pin_led_01, HIGH); //Led01(CERTO)
    	fase = 2;
      	break;
  	}else if(estado_buttom_direita == HIGH){
    	digitalWrite(pin_led_02, HIGH);//Led02(ERRADO)
    	fase = 2;
      	break;
  	}
  }
}

void fase2(){
  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
  	// se a pessoa foi pro caminho certo
  	if(digitalRead(pin_led_01) == HIGH){  // se o Led01 está ligado
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
    	Serial.println("Botão esquerdo: ");
    	Serial.println(estado_buttom_esquerda);
    	Serial.println("Botão direito: ");
    	Serial.println(estado_buttom_direita);
    	digitalWrite(pin_led_03, HIGH);//Led03
    	digitalWrite(pin_led_04, HIGH);//Led04
    	delay(400);
    	digitalWrite(pin_led_03, LOW);//Led03
    	digitalWrite(pin_led_04, LOW);//Led04
    	delay(400);
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
    	if(estado_buttom_esquerda == HIGH){;
      		digitalWrite(pin_led_03, HIGH);//Led03(CERTO)
      		fase = 3;
          	break;
    	}else if(estado_buttom_direita == HIGH){
      		digitalWrite(pin_led_04, HIGH);//Led04(ERRADO)
      		Serial.println("Botão direito apertado");
      		Serial.println(estado_buttom_direita);
      		fase = 3;
          	break;
    	}
  	}else if(digitalRead(pin_led_02) == HIGH){
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
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
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
    	if(estado_buttom_esquerda == HIGH){
      		digitalWrite(pin_led_08, HIGH);
      		fase = 3;
          	break;
    	}else if(estado_buttom_direita == HIGH){
      		digitalWrite(pin_led_07, HIGH);
      		fase = 3;
          	break;
    	}
    }
  }
}

void fase3(){
  while(estado_buttom_esquerda != HIGH || estado_buttom_direita != HIGH){
  	if(digitalRead(pin_led_03) == HIGH){
    	estado_buttom_esquerda = digitalRead(3);
    	estado_buttom_direita = digitalRead(2);
    	Serial.println("Botão esquerdo: ");
    	Serial.println(estado_buttom_esquerda);
    	Serial.println("Botão direito: ");
    	Serial.println(estado_buttom_direita);
    	digitalWrite(pin_led_06, HIGH);
    	delay(400);
    	digitalWrite(pin_led_06, LOW);
    	delay(400);
    	estado_buttom_esquerda = digitalRead(3);
    	estado_buttom_direita = digitalRead(2);
    	if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      		digitalWrite(pin_led_06, HIGH);//CHEGOU AO FIM
      		fase = 4;
      		break;
    	}
  	}
  
  	else if(digitalRead(pin_led_04) == HIGH){
    	estado_buttom_esquerda = digitalRead(3);
    	estado_buttom_direita = digitalRead(2);
    	Serial.println("Botão esquerdo: ");
    	Serial.println(estado_buttom_esquerda);
    	Serial.println("Botão direito: ");
    	Serial.println(estado_buttom_direita);
    	digitalWrite(pin_led_05, HIGH);
    	delay(400);
    	digitalWrite(pin_led_05, LOW);
    	delay(400);
    	estado_buttom_esquerda = digitalRead(3);
    	estado_buttom_direita = digitalRead(2);
    	if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      		digitalWrite(pin_led_05, HIGH);
      		fase = 4;
      		break;
    	}
  	}
  
  	else if(digitalRead(pin_led_08) == HIGH){
  		fase = 4;
    	break;
  	}
  
  	else if(digitalRead(pin_led_07) == HIGH){
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
        Serial.println("Botão esquerdo: ");
    	Serial.println(estado_buttom_esquerda);
    	Serial.println("Botão direito: ");
      	Serial.println(estado_buttom_direita);
        estado_buttom_esquerda = digitalRead(3);
  		estado_buttom_direita = digitalRead(2);
    	digitalWrite(pin_led_09, HIGH);
    	delay(400);
    	digitalWrite(pin_led_09, LOW);
    	delay(400);
    	if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      		digitalWrite(pin_led_09, HIGH);
      		fase = 4;
          	break;
    	}
    }
  }
}

void fase4(){
  estado_buttom_esquerda = digitalRead(3);
  estado_buttom_direita = digitalRead(2);
  if(digitalRead(pin_led_06) == HIGH){
    digitalWrite(pin_led_f, HIGH);
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      fase = 1;
    }
  }else{
    if(estado_buttom_esquerda == HIGH || estado_buttom_direita == HIGH){
      fase = 1;
  	}
  }
}
