#define LED 13

int SpeedFrontLeft = 150;
int SpeedFrontRight = 150;
int SpeedRearLeft = 150;
int SpeedRearRight = 150;

int MAXSPEED = 255;

int Speedsec;

const int freq = 30000;
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int pwmChannel3 = 2;
const int pwmChannel4 = 3;
const int resolution = 8;

class DCMotor{
  int spd = 100, pin1, pin2, enable1Pin, pwmChannelForThisMotor;

  public:

    void pinOut(int in1, int in2, int en, int pwmChannelForThisMotor)
    {
      pin1 = in1;
      pin2 = in2;
      enable1Pin = en;
      this->pwmChannelForThisMotor = pwmChannelForThisMotor;
      
      
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(enable1Pin, OUTPUT);


      ledcSetup(this->pwmChannelForThisMotor, freq, resolution);
      ledcAttachPin(enable1Pin, this->pwmChannelForThisMotor);

    }

    void Speed(int in1)
    {
      spd = in1;
    }

    void Forward()
    {
      //quando colocar o pwm trocar o digitalwrite do pin1 para analogwrite
      //analogWrite(pin1, spd);
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
      ledcWrite(pwmChannel, spd);
    }

    void Backward()
    {
      //quando colocar o pwm trocar o digitalwrite do pin1 para analogwrite
      //digitalWrite(pin1, LOW); //pin1 gira a roda no sentido horario
      //digitalWrite(pin1, LOW); //pin1 gira a roda no sentido horario
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

DCMotor LeftMotorFront, LeftMotorRear, RightMotorFront, RightMotorRear; //criando os 4 motores(rodas), que vão receber os metodos acima

void setup(){
  Serial.begin(9600);
  
  LeftMotorFront.pinOut(26, 25, 33, pwmChannel);
  LeftMotorRear.pinOut(17, 16, 4, pwmChannel2);
  RightMotorFront.pinOut(19, 18, 23, pwmChannel3);
  RightMotorRear.pinOut(12, 27, 14, pwmChannel4);

  
  

  Serial.println("fim setup");
}

void loop() 
{
  

  static int counter = 0;

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
    
  }else if (counter >= 9 && counter < 12){
    LeftMotorFront.Speed(MAXSPEED);
    LeftMotorRear.Speed(MAXSPEED);
    RightMotorFront.Speed(MAXSPEED);
    RightMotorRear.Speed(MAXSPEED);
    Serial.print("FOURTH IF!!!!!!");
    right();
    delay(1000);
    counter++;
  }
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
