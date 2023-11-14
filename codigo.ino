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

void setup(){
  Serial.begin (9600);
  //led_labirinto
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_led_e, OUTPUT);
  pinMode(pin_led_s, OUTPUT);
  //potenciometro
  pinMode(pin_pot1, INPUT);
  pinMode(pin_pot2, INPUT);
  //led_rgb
  pinMode (vermelho, OUTPUT); 
  pinMode (verde, OUTPUT); 
  pinMode (azul, OUTPUT); 
  digitalWrite(azul, LOW); 
  digitalWrite(verde, LOW); 
  digitalWrite(vermelho, HIGH); 
} 
void loop(){
 //mapeamento pot
  potvalor1 = analogRead(pin_pot1);
  potvalor2 = analogRead(pin_pot2);
  valor_nmd1 = map(potvalor1, 0, 1023, 0, 180);
  valor_nmd2 = map(potvalor2, 0, 1023, 0, 180);//Ajeitar os valores
  digitalWrite(pin_led_e, HIGH);
  delay(1000);
  
  if(1>valor_nmd1>5){
  
  }
  
}

//Códigos q ainda vão ser usados
// digitalWrite(pin_led_Vd, HIGH);
// digitalWrite(pin_led_Vm, LOW);
//delay(1000);
//valor_fotor = analogRead(pin_fotor);
//valor_normalizado = map(valor_fotor, 0, 1023, 0, 180);
//SetColor = (255, 0, 0);//Red
//delay(1000);
//SetColor = (0, 255, 0);//green
//SetColor = (255, 255, 0);//yellow
