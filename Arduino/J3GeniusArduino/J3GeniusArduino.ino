
#define AMARELO 0
#define AZUL 1
#define VERDE 2
#define VERMELHO 3

#define BUZZER 13

#define BTN_AMARELO 8
#define BTN_AZUL 9
#define BTN_VERDE 10
#define BTN_VERMELHO 11

const int sequencia[] = {AMARELO, AZUL, VERDE, VERMELHO};

int melody[] = {
  300, 600, 900, 1200, 1500, 1800, 2100, 2700
};

void setup() {
 pinMode(AMARELO, OUTPUT);  
 pinMode(AZUL, OUTPUT);  
 pinMode(VERDE, OUTPUT);  
 pinMode(VERMELHO, OUTPUT);  

 pinMode(BTN_AMARELO, INPUT_PULLUP);  
 pinMode(BTN_AZUL, INPUT_PULLUP);  
 pinMode(BTN_VERDE, INPUT_PULLUP);  
 pinMode(BTN_VERMELHO, INPUT_PULLUP);  

digitalWrite(AMARELO, LOW); 
digitalWrite(AZUL, LOW); 
digitalWrite(VERDE, LOW); 
digitalWrite(VERMELHO, LOW);
}

void loop() {
  Iniciar();

 
    digitalWrite(AMARELO, LOW); 
    digitalWrite(AZUL, LOW); 
    digitalWrite(VERDE, LOW); 
    digitalWrite(VERMELHO, LOW);
    delay(200);
    digitalWrite(AMARELO, HIGH);  
    digitalWrite(AZUL, HIGH); 
    digitalWrite(VERDE, HIGH); 
    digitalWrite(VERMELHO, HIGH);
    delay(200);
    digitalWrite(AMARELO, LOW); 
    digitalWrite(AZUL, LOW); 
    digitalWrite(VERDE, LOW); 
    digitalWrite(VERMELHO, LOW);
    delay(200);
    digitalWrite(AMARELO, HIGH);  
    digitalWrite(AZUL, HIGH); 
    digitalWrite(VERDE, HIGH); 
    digitalWrite(VERMELHO, HIGH);
    delay(200);

    digitalWrite(AMARELO, LOW); 
    digitalWrite(AZUL, LOW); 
    digitalWrite(VERDE, LOW); 
    digitalWrite(VERMELHO, LOW);
    delay(1000);

  Jogando();

  Perdeu();
}


void Iniciar(){
  
  int iSequencia = 0;
  long fatorRandom = 0; 

  while(1){
    if((digitalRead(BTN_AMARELO) == LOW) or (digitalRead(BTN_AZUL) == LOW) or (digitalRead(BTN_VERDE) == LOW) or (digitalRead(BTN_VERMELHO) == LOW) ){
      randomSeed(fatorRandom); // Inicializa o gerador de números pseudoaleatórios de acordo com o momento que o usuario iniciar o jogo 
      return;
    } 
    digitalWrite(sequencia[iSequencia], HIGH); 
    delay(250);            
    digitalWrite(sequencia[iSequencia], LOW); 

    iSequencia++;
    if (iSequencia == 4)
     iSequencia = 0;
    
    fatorRandom++; 
  }

}

void JogandoPisca(int _num){
  digitalWrite(_num, HIGH); 
  
  if (_num == AMARELO)
    tone(BUZZER, 264, 250);
  else if (_num == AZUL)  
    tone(BUZZER, 330, 250);
  else if (_num == VERDE)  
    tone(BUZZER, 396, 250);
  else if (_num == VERMELHO)  
    tone(BUZZER, 495, 250);
  
  delay(250);            
  digitalWrite(_num, LOW);
  delay(500);    
}

int AguardaJogada(){
  while(1){
    if(digitalRead(BTN_AMARELO) == LOW)
      return 0;
    if(digitalRead(BTN_AZUL) == LOW)
      return 1;
    if(digitalRead(BTN_VERDE) == LOW)
      return 2;
    if(digitalRead(BTN_VERMELHO) == LOW)
      return 3;
  }
}

void Jogando(){
  int seguencia[50] = {};
  int iJogador = 0;
  bool errou = false;
  int btnJogado;
  byte iJogado = 0;
  
  for(byte i=0; i < 50; i++) {
    seguencia[i] = -1;
  }

  while(!errou){  
    iJogado = 0;
    seguencia[iJogador] = random(4);

    for(byte i=0; i<=iJogador; i++){
      JogandoPisca(seguencia[i]);
    }
  
    while(iJogado <= iJogador){
      btnJogado = AguardaJogada();
      if (btnJogado == seguencia[iJogado]){
        JogandoPisca(btnJogado);
        iJogado++;
      }else{
        errou = true;
        break;
      }
    }
    iJogador++;
  }
}

void Perdeu(){
    bool EstadoLED = false;
    for(int i=0; i<=7;i++){
      digitalWrite(AMARELO, EstadoLED); 
      digitalWrite(AZUL, EstadoLED); 
      digitalWrite(VERDE, EstadoLED); 
      digitalWrite(VERMELHO, EstadoLED); 
      tone(BUZZER, melody[i], 250);
      EstadoLED = !EstadoLED;
      delay(500);
    }
    digitalWrite(AMARELO, LOW); 
    digitalWrite(AZUL, LOW); 
    digitalWrite(VERDE, LOW); 
    digitalWrite(VERMELHO, LOW); 
    delay(500);
}


