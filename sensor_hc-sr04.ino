// Definir pinos
const int trigPin = 6;  //Pino TRIG no pino 6 (TRIG = Trigger = Gatilho/Início)
const int echoPin = 7;  //Pino ECHO no pino 7
const int buzzer = 8;   //Buzzer no pino 8

// Definir variáveis
long duracao;   //Armazena a duração do pulso ultrassônico
int distancia;  //Armazena a distância do pulso ultrassônico

//Código que roda na inicialização do Arduino
void setup()
{
  pinMode(trigPin, OUTPUT); //Configura o trigPin como saída de dados (envia o pulso)
  pinMode(echoPin, INPUT);  //Configura o echoPin como entrada de dados (recebe o pulso)
  pinMode(buzzer, OUTPUT);  //Configura o buzzer como saída de dados (apitar ou não)
  Serial.begin(9600);       //Inicia o monitor serial para verificarmos as distâncias
}

//Código que roda o tempo todo
void loop()
{
  digitalWrite(trigPin, LOW);       //Zera o pino Trigger antes de realizar um novo pulso
  delayMicroseconds(2);             //Aguarda 2 μs
  digitalWrite(trigPin, HIGH);      //Liga o pino Trigger para realizar um novo pulso
  delayMicroseconds(10);            //Aguarda 10 μs
  digitalWrite(trigPin, LOW);       //Desliga o pino Trigger para não enviar mais pulsos e podermos calcular a distância
  duracao = pulseIn(echoPin, HIGH); //Calcula a duração do pulso anterior
  distancia = duracao *0.034 / 2;   //Calcula a distância a partir da duração do pulso e da velocidade do som

  //Entre 40-50 cm
  if (distancia > 40 && distancia < 50)
  {
    digitalWrite(buzzer, HIGH); //Liga o buzzer
    delay(500);                 //Aguarda 500 ms (1/2 segundo)
    digitalWrite(buzzer, LOW);  //Desliga o buzzer
  }

  //Entre 30-40 cm
  if (distancia > 30 && distancia < 40)
  {
    digitalWrite(buzzer, HIGH); //Liga o buzzer
    delay(250);                 //Aguarda 250 ms
    digitalWrite(buzzer, LOW);  //Desliga o buzzer
  }

  //Entre 20-30 cm
  if (distancia > 20 && distancia < 30)
  {
    digitalWrite(buzzer, HIGH); //Liga o buzzer
    delay(100);                 //Aguarda 100 ms
    digitalWrite(buzzer, LOW);  //Desliga o buzzer
  }

  //Entre 10-20 cm
  if (distancia > 10 && distancia < 20)
  {
    digitalWrite(buzzer, HIGH); //Liga o buzzer
    delay(50);                  //Aguarda 50 ms
    digitalWrite(buzzer, LOW);  //Desliga o buzzer
  }

  //Abaixo de 10cm
  if (distancia < 10)
  {
    digitalWrite(buzzer, HIGH); //Liga o buzzer
    delay(1000);                //Aguarda 1000 ms (1 segundo)
    digitalWrite(buzzer, LOW);  //Desliga o buzzer
  }
}
