//Programa: Motor DC com encoder
//Autor: Arduino e Cia

const byte Encoder_C1 = 5;
const byte Encoder_C2 = 4;
byte Encoder_C1Last;
int duracao;
boolean Direcao;

//Pinos de ligacao ponte H L298N
#define pino_LeftMotor1 26
#define pino_LeftMotor2 25
#define pino_RightMotor 19
#define pino_RightMotor 18

void setup()
{
  Serial.begin(9600);
  //Definicao pinos ponte H
  pinMode(pino_LeftMotor1, OUTPUT);
  pinMode(pino_LeftMotor2, OUTPUT);

  pinMode(pino_RightMotor1, OUTPUT);
  pinMode(pino_RightMotor2, OUTPUT);
  //Definicao do encoder
  EncoderInit();
}

void loop()
{
  Serial.print("Pulso: ");
  Serial.print(duracao);
  
    digitalWrite(pino_LeftMotor1, LOW);
    digitalWrite(pino_LeftMotor2, LOW);
    digitalWrite(pino_RightMotor1, LOW);
    digitalWrite(pino_RightMotor2, LOW);
    //delay(1000);
    digitalWrite(pino_LeftMotor1, LOW);
    digitalWrite(pino_LeftMotor2, HIGH);
    digitalWrite(pino_RightMotor1, LOW);
    digitalWrite(pino_RightMotor2, HIGH);
    Serial.println(" Sentido: Anti-horario");

    digitalWrite(pino_LeftMotor1, HIGH);
    digitalWrite(pino_LeftMotor2, LOW);
    digitalWrite(pino_RightMotor1, HIGH);
    digitalWrite(pino_RightMotor2, LOW);
    Serial.println(" Sentido: Horario");

  duracao = 0;
  delay(100);
}

void EncoderInit()
{
  pinMode(Encoder_C2, INPUT);
  attachInterrupt(0, calculapulso, CHANGE);
}

void calculapulso()
{
  int Lstate = digitalRead(Encoder_C1);
  if ((Encoder_C1Last == LOW) && Lstate == HIGH)
  {
    int val = digitalRead(Encoder_C2);
    if (val == LOW && Direcao)
    {
      Direcao = false; //Reverse
    }
    else if (val == HIGH && !Direcao)
    {
      Direcao = true;  //Forward
    }
  }
  Encoder_C1Last = Lstate;

  if (!Direcao)  duracao++;
  else  duracao--;
}