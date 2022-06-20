int PinoVelocidade = 3;
int Entrada1 = 2;
int Entrada2 = 6;                                                                                ;
int Entrada3 = 9;
int Entrada4 = 10;
int LDR = A5;
int led = 4;
int valorLDR = 0;
const int buzzer = 7;
bool tocar = false;

void setup() {
  pinMode(PinoVelocidade, OUTPUT);
  pinMode(Entrada1, OUTPUT);
  pinMode(Entrada2, OUTPUT);
  pinMode(Entrada3, OUTPUT);
  pinMode(Entrada4, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode (led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void musica(){
  if(tocar == false){
    tone(buzzer,660,100);
    delay(150);
    tone(buzzer,660,100);
    delay(300);
    tone(buzzer,660,100);
    delay(300);
    tone(buzzer,510,100);
    delay(100);
    tone(buzzer,660,100);
    delay(300);
    tone(buzzer,770,100);
    delay(550);
    tone(buzzer,380,100);
    delay(575);
    noTone(buzzer);
  }
  tocar = true;
}

void loop() {
  valorLDR = analogRead(LDR);
  Serial.println(valorLDR);
  int velocidade = 500;

 if(valorLDR > 800){
  musica();
  analogWrite(PinoVelocidade, velocidade);
  digitalWrite(Entrada1, LOW);
  digitalWrite(Entrada2, HIGH);
  digitalWrite(Entrada3, LOW);
  digitalWrite(Entrada4, HIGH);

  delay(500);

  digitalWrite(Entrada1, HIGH);
  digitalWrite(Entrada2, LOW);
  digitalWrite(Entrada3, HIGH);
  digitalWrite(Entrada4, LOW);

  digitalWrite (led,HIGH);

  } else {
    digitalWrite (led,LOW);
    tocar = false;
  }
 
}

void para_motor(){
  digitalWrite(Entrada1, LOW);
  digitalWrite(Entrada2, LOW);
  delay(300);
  
}





