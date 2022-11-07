#define led_amarelo 21
#define led_azul 5
#define led_verde 18
#define led_branco 19
#define LDR 25
#define buzzer 23
#define botao_verde 35
#define botao_azul 14

int vetor[4];
int ledArmazenado[50][4];
int valorArmazenado = 0;
int led[4] = {led_amarelo, led_azul, led_verde, led_branco};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_branco, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(botao_verde, INPUT_PULLUP);
  pinMode(botao_azul, INPUT_PULLUP);
  
}



// função com retorno vazio que converte o número lido pelo LDR para binário
void binary(int value) {
  for (int i = 0; i < 4; i++) {
    vetor[i] = value % 2;
    ledArmazenado[valorArmazenado][i] = value % 2;
    value = value / 2;
  }
  valorArmazenado = valorArmazenado +1;
}

// função com retorno vazio que faz com que cada LED ligue ou desligue de acordo
//com seu valor binário

void showLed(int element, int led) {
  if (element == 1) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}

// função com retorno vazio que toca um som para cada frequência lida pelo LDR

void toque(int *vetor) {
  int song = 0;
  for (int i = 0; i < 4; i++) {
    song += vetor[i] *i* 500;
  }
  tone(buzzer, song , 500);
}

//loop do código que mostra dois if's , um para cada botão, fazendo o que o exercício
//pede, isto é, se um botao for ativado, irá ler o valor do LDR, converter para binário,
//acender as luzes e tocar cada frequência, logo após irá apagar todos, já para o 
//outro botão exibe nos LEDs, em sequência, todos os valores armazenados no vetor
// anterior e, ao mesmo tempo, tocar seu respectivo som através do buzzer.

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(botao_verde) == LOW) {
    

    int valorLido = analogRead(LDR);
    int valorConvertido = valorLido / 273;
    binary(valorConvertido);
    showLed(vetor[0], led_amarelo);
    showLed(vetor[1], led_azul);
    showLed(vetor[2], led_verde);
    showLed(vetor[3], led_branco);
    toque(vetor);
    delay(500);
    showLed(0, led_amarelo);
    showLed(0, led_azul);
    showLed(0, led_verde);
    showLed(0, led_branco);
  while (digitalRead(botao_verde) == LOW) {}
  } 
  
  if (digitalRead(botao_azul) == LOW) {
   
    for (int i = 0; i < valorArmazenado; i++) {
      showLed(ledArmazenado[i][0], led_amarelo);
      showLed(ledArmazenado[i][1], led_azul);
      showLed(ledArmazenado[i][2], led_verde);
      showLed(ledArmazenado[i][3], led_branco);
      toque(ledArmazenado[i]);
      delay(1000);
      showLed(0, led_amarelo);
      showLed(0, led_azul);
      showLed(0, led_verde);
      showLed(0, led_branco);
      delay(1000);
    }
    valorArmazenado = 0;

     while (digitalRead(botao_azul) == LOW) {}
  }
  delay(100);
  // this speeds up the simulation
}