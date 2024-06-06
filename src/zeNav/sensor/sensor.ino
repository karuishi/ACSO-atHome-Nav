#define LED 13

int Speed = 120;
int Speedsec;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

class DCMotor{
  int spd = 255, pin1, pin2;
  int parado = 0;

  public:

    void pinOut(int in1, int in2){
      pin1 = in1;
      pin2 = in2;
      
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      //ledcSetup(pwmChannel, freq, resolution);
    }

    void Speed(int in1){
      spd = in1;
    }

    void Forward(){
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      analogWrite(pin1, spd); //pin1 gira a roda no sentido horario
      digitalWrite(pin2, LOW); //o pin2 gira a roda no sentido antihorario "para trás"
//      ledcWrite/(pwmChannel, spd); //pwm ativar dps
    }

    void Backward(){
      //quando colocar o pwm trocar o digitalwrite do pin1 para analogwrite
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
      digitalWrite(pin1, LOW); //pin1 gira a roda no sentido horario
      analogWrite(pin2, spd); //o pin2 gira a roda no sentido antihorario "para trás"
//     ledcWrite(pwmChannel, spd/); //pwm ativar dps
    }

    void Stop() { // Stop é o metodo para fazer o motor ficar parado.
      //Serial.println("Motor stopped");
      analogWrite(pin1, parado);
      analogWrite(pin2, parado);
    }
};

DCMotor LeftMotorFront, LeftMotorRear, RightMotorFront, RightMotorRear; //criando os 4 motores(rodas), que vão receber os metodos acima

void setup(){
  Serial.begin(115200);
  
  LeftMotorFront.pinOut(26, 25);
  LeftMotorRear.pinOut(17, 16);
  RightMotorFront.pinOut(19, 18);
  RightMotorRear.pinOut(12, 27);

  pinMode(15, INPUT); //declarando a porta do sensor

  Serial.println("fim setup");
}

void loop(){
  

  Stop();

  }

void Stop(){
    LeftMotorFront.Stop();  // Comando para o motor parar
    LeftMotorRear.Stop();   // Comando para o motor parar
    RightMotorFront.Stop(); // Comando para o motor parar
    RightMotorRear.Stop();  // Comando para o motor parar
  }

void forward(){
    Serial.print("Moving forward  ");
    Serial.print("spd: ");
    Serial.println(Speed);
    LeftMotorFront.Forward();   // Comando para o motor ir para frente
    LeftMotorRear.Forward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();   // Comando para o motor ir para frente
  }

void back(){
    Serial.print("Moving back  ");
    Serial.print("spd: ");
    Serial.println(Speed);
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();   // Comando para o motor ir para trás
    RightMotorFront.Backward(); // Comando para o motor ir para trás
    RightMotorRear.Backward();  // Comando para o motor ir para trás
  }

void left() {
    Serial.print("Moving left  ");
    Serial.print("spd: ");
    Serial.println(Speed);
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();  // Comando para o motor ir para trás
  }

void right() {
    Serial.print("Moving right  ");
    Serial.print("spd: ");
    Serial.println(Speed);
    LeftMotorFront.Forward();   // Comando para o motor ir para frente
    LeftMotorRear.Forward();   // Comando para o motor ir para trás
    RightMotorFront.Backward(); // Comando para o motor ir para trás
    RightMotorRear.Backward();   // Comando para o motor ir para frente
  }

//stationary rotation (spin)-testando
void superleft() {
  Serial.print("stationary rotation (spin) - superleft  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Backward();  // Comando para o motor ir para trás
  LeftMotorRear.Forward();   // Comando para o motor parar
  RightMotorFront.Forward(); // Comando para o motor parar
  RightMotorRear.Backward();  // Comando para o motor ir para trás
}
//stationary rotation (spin)-testando
void superright() {
  Serial.print("stationary rotation (spin) - superright  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Forward();  // Comando para o motor parar
  LeftMotorRear.Backward();   // Comando para o motor parar
  RightMotorFront.Backward(); // Comando para o motor parar
  RightMotorRear.Forward();  // Comando para o motor parar
}

void forwardleft() {
  Serial.print("Moving forwardleft  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Stop();  // Comando para o motor parar
  LeftMotorRear.Stop();    // Comando para o motor ir para frente
  RightMotorFront.Forward();  // Comando para o motor ir para frente
  RightMotorRear.Forward();  // Comando para o motor parar
}
void forwardright() {
  Serial.print("Moving forwardright  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Forward();   // Comando para o motor ir para frente
  LeftMotorRear.Forward();   // Comando para o motor parar
  RightMotorFront.Stop();  // Comando para o motor ir para frente
  RightMotorRear.Stop();   // Comando para o motor ir para frente
}

void backright() {
  Serial.print("Moving backright  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Stop();  // Comando para o motor parar
  LeftMotorRear.Stop();   // Comando para o motor ir para trás
  RightMotorFront.Backward(); // Comando para o motor ir para trás
  RightMotorRear.Backward();  // Comando para o motor parar
}

void backleft() {
  Serial.print("Moving backleft  ");
  Serial.print("spd: ");
  Serial.println(Speed);
  LeftMotorFront.Backward();  // Comando para o motor ir para trás
  LeftMotorRear.Backward();   // Comando para o motor parar
  RightMotorFront.Stop(); // Comando para o motor parar
  RightMotorRear.Stop();  // Comando para o motor ir para trás
}
