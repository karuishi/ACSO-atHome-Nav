#define LED 13

// 1 forma de setar o valor da velocidade dos motores, onde os valores ficam como "default"
int SpeedFrontLeft = 150;
int SpeedFrontRight = 150;
int SpeedRearLeft = 150;
int SpeedRearRight = 150;

// Criando a variavel MAXSPEED para setar o maximo da velocidade do motor, foi necessário na hora de ir para a direita e para a esquerda pois na default não havia força suficiente
int MAXSPEED = 255;

int Speedsec;

// Declarando as variáveis de frequencia, resolução e dos canais do pwm(por motor)
const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int pwmChannel3 = 2;
const int pwmChannel4 = 3;
const int resolution = 8;

class DCMotor{

  // Declarando dentro da classe as variaveis de speed(poderia ser sem valor), da porta logica pinos e do pwm, e do canal pwm para o respectivo motor
  int spd = 100, pin1, pin2, enable1Pin, pwmChannelForThisMotor;

  public:

    // Criando o metodo pinOut com função para atribuir valor as variaveis declaradas, "this->" é uma forma de chamar a variavel declarada na classe, e não na metodo/função 
    void pinOut(int in1, int in2, int en, int pwmChannelForThisMotor)
    {
      pin1 = in1;
      pin2 = in2;
      enable1Pin = en;
      this->pwmChannelForThisMotor = pwmChannelForThisMotor;
      
      
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(enable1Pin, OUTPUT);

      // Comando do arduino para setar os parametros do pwm(canal, frequencia, resolucao)
      ledcSetup(this->pwmChannelForThisMotor, freq, resolution);
      ledcAttachPin(enable1Pin, this->pwmChannelForThisMotor);

    }

    // Metodo speed com a funçao de definir a velocidade do motor
    void Speed(int in1)
    {
      spd = in1;
    }

    // Comando para definir os parametros dos pinos, no caso o pino 1 vai ser atribuido com o valor analogico da velocidade e  2 o comando digital LOW, ledcwrite passa o parametro do canal pwm
    void Forward()
    {
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
      ledcWrite(pwmChannel, spd);
    }

    // Comando para definir os parametros dos pinos, no caso o pino 2 vai ser atribuido com o valor analogico da velocidade e  1 o comando digital LOW, ledcwrite passa o parametro do canal pwm
    void Backward()
    {
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      digitalWrite(pin1, LOW);
      analogWrite(pin2, spd);
      ledcWrite(pwmChannel, spd);
    }

    void Stop() 
    { // Stop é o metodo para fazer o motor ficar parado.
      //Serial.println("Motor stopped");
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      digitalWrite(this->pin1, LOW);
      digitalWrite(this->pin2, LOW);
    }
};

DCMotor LeftMotorFront, LeftMotorRear, RightMotorFront, RightMotorRear; //Instanciado os objetos, no caso, os 4 motores(rodas) que vão receber os metodos acima

void setup(){

  // Comandos serial.begin e posteriormente serial.print para acompanharmos a execução dos comandos via terminal e posteriormente realizar as devidas correções
  Serial.begin(9600);
  
  // Atribuido o valor dos pinos e do pwm, assim como o respectivo canal de cada um
  LeftMotorFront.pinOut(26, 25, 33, pwmChannel);
  LeftMotorRear.pinOut(17, 16, 4, pwmChannel2);
  RightMotorFront.pinOut(19, 18, 23, pwmChannel3);
  RightMotorRear.pinOut(12, 27, 14, pwmChannel4);

  
  

  Serial.println("fim setup");
}

void loop() 
{
  
  // Criação do contador estático para mudar a direção do Ze a partir das condicionais atribuidas enquanto o loop acontece
  static int counter = 0;

  // Enquanto estiver no intervalo 0,1,2 o Ze seguirá em frente enquanto no painel sera impresso o first if
  if (counter < 3)
  {
    LeftMotorFront.Speed(SpeedFrontLeft);
    LeftMotorRear.Speed(SpeedRearLeft);
    RightMotorFront.Speed(SpeedFrontRight);
    RightMotorRear.Speed(SpeedRearRight);
    Serial.print("FIRST IF!!!!!!!  ");
    forward();
    delay(1000);
    counter++;
  }

  // Enquanto estiver no intervalo 3,4,5 o Ze irá mover-se para a esquerda enquanto no painel sera impresso o second if, com a mudança do MAXSPEED no local das respectivas variaveis de velocidade
  else if (counter >= 3 && counter < 6)
  {
    LeftMotorFront.Speed(MAXSPEED);
    LeftMotorRear.Speed(MAXSPEED);
    RightMotorFront.Speed(MAXSPEED);
    RightMotorRear.Speed(MAXSPEED);
    Serial.print("SECOND IF!!!!!!!  ");
    left();
    delay(1000);
    counter++;
  }

  // Enquanto estiver no intervalo 6,7,8 o Ze irá mover-se para trás enquanto no painel sera impresso o third if
  else if (counter >= 6 && counter < 9)
  {
    LeftMotorFront.Speed(SpeedFrontLeft);
    LeftMotorRear.Speed(SpeedRearLeft);
    RightMotorFront.Speed(SpeedFrontRight);
    RightMotorRear.Speed(SpeedRearRight);
    Serial.print("THIRD IF!!!!!!");
    back();
    delay(1000);
    counter++;
    
  }
  
  // Enquanto estiver no intervalo 9,10,11 o Ze irá mover-se para a direita enquanto no painel sera impresso o fourth if, com a mudança do MAXSPEED no local das respectivas variaveis de velocidade
  else if (counter >= 9 && counter < 12)
  {
    LeftMotorFront.Speed(MAXSPEED);
    LeftMotorRear.Speed(MAXSPEED);
    RightMotorFront.Speed(MAXSPEED);
    RightMotorRear.Speed(MAXSPEED);
    Serial.print("FOURTH IF!!!!!!");
    right();
    delay(1000);
    counter++;
  }
  
  // Quando o contador atingir o valor inteiro 12, o Ze irá chamar o Metodo Stop, fazendo- o parar no lugar
  else
  {
    stop();
  }
  

  
}

void stop(){
    LeftMotorFront.Stop();  // Comando para o motor parar
    LeftMotorRear.Stop();   // Comando para o motor parar
    RightMotorFront.Stop(); // Comando para o motor parar
    RightMotorRear.Stop();  // Comando para o motor parar
  }

void forward(){
    Serial.print("Moving forward  ");
    Serial.print("spd: ");
    Serial.println(SpeedFrontLeft);
    Serial.println(SpeedRearLeft);
    Serial.println(SpeedFrontRight);
    Serial.println(SpeedRearRight);
    LeftMotorFront.Forward();   // Comando para o motor ir para frente
    LeftMotorRear.Forward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();   // Comando para o motor ir para frente
  }

void back(){
    Serial.print("Moving back  ");
    Serial.print("spd: ");
    Serial.println(SpeedFrontLeft);
    Serial.println(SpeedRearLeft);
    Serial.println(SpeedFrontRight);
    Serial.println(SpeedRearRight);
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();   // Comando para o motor ir para trás
    RightMotorFront.Backward(); // Comando para o motor ir para trás
    RightMotorRear.Backward();  // Comando para o motor ir para trás
  }

void left() {
    Serial.print("Moving left  ");
    Serial.print("spd: ");
    Serial.println(SpeedFrontLeft);
    Serial.println(SpeedRearLeft);
    Serial.println(SpeedFrontRight);
    Serial.println(SpeedRearRight);
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();  // Comando para o motor ir para trás
  }

void right() {
    Serial.print("Moving right  ");
    Serial.print("spd: ");
    Serial.println(SpeedFrontLeft);
    Serial.println(SpeedRearLeft);
    Serial.println(SpeedFrontRight);
    Serial.println(SpeedRearRight);
    LeftMotorFront.Forward();   // Comando para o motor ir para frente
    LeftMotorRear.Forward();   // Comando para o motor ir para trás
    RightMotorFront.Backward(); // Comando para o motor ir para trás
    RightMotorRear.Backward();   // Comando para o motor ir para frente
  }
