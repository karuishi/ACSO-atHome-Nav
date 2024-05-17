// #define LeftMotorFront1 26
// #define LeftMotorFront2 25

// #define LeftMotorRear1 17
// #define LeftMotorRear2 16

// #define RightMotorFront1 19
// #define RightMotorFront2 18

// #define RightMotorRear1 12
// #define RightMotorRear2 27

#define HIGH 100

// dev - Adicionado Classe motor e metodo pinOut com entrada de dados
class Motor{

  public:

  void pinOut(int nA, int nB){
    int pinA = nA;
    int pinB = nB;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
  }

  // dev - criando o forward na classe para ser chamado no loop

  void Forward(){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
  }

  // dev - criando o backward na classe para ser chamado no loop

  void Backward(){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
  }
  
  void Stop(){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
  }

};

// dev - Adicinado objetos

Motor LeftMotorFront, LeftMotorRear, RightMotorFront, RightMotorRear;



void setup() {


  // pinMode(LeftMotorFront1, OUTPUT);
  // pinMode(LeftMotorFront2, OUTPUT);

  // dev - Inserindo valor a função do metodo pinout

  LeftMotorFront.pinOut(26, 25);

  // pinMode(LeftMotorRear1, OUTPUT);
  // pinMode(LeftMotorRear2, OUTPUT);

  // dev - Inserindo valor a função do metodo pinout

  LeftMotorRear.pinOut(17, 16);

  // pinMode(RightMotorFront1, OUTPUT);
  // pinMode(RightMotorFront2, OUTPUT);

  // dev - Inserindo valor a função do metodo pinout

  RightMotorFront.pinOut(19, 18);

  // pinMode(RightMotorRear1, OUTPUT);
  // pinMode(RightMotorRear2, OUTPUT);

  // dev - Inserindo valor a função do metodo pinout

  RightMotorRear.pinOut(12, 27);

  pinMode(3, OUTPUT);  //nao entendi a interação desses comandos
  analogWrite(3, LOW); //nao entendi a interação desses comandos


}
  // void forward(){
  // digitalWrite(LeftMotorFront1, HIGH);
  // digitalWrite(RightMotorFront1, HIGH);
  // digitalWrite(LeftMotorFront2, LOW);
  // digitalWrite(RightMotorFront2, LOW);

  // digitalWrite(LeftMotorRear1, HIGH);
  // digitalWrite(RightMotorRear1, HIGH);
  // digitalWrite(LeftMotorRear2, LOW);
  // digitalWrite(RightMotorRear2, LOW);
  // }

  void forward(){
    LeftMotorFront.Forward();
    RightMotorFront.Forward();
    LeftMotorRear.Forward();
    RightMotorRear.Forward();
  }
  

// void backward(){
//   digitalWrite(LeftMotorFront1, LOW);
//   digitalWrite(RightMotorFront1, LOW);
//   digitalWrite(LeftMotorFront2, HIGH);
//   digitalWrite(RightMotorFront2, HIGH);

//   digitalWrite(LeftMotorRear1, LOW);
//   digitalWrite(RightMotorRear1, LOW);
//   digitalWrite(LeftMotorRear2, HIGH);
//   digitalWrite(RightMotorRear2, HIGH);
// }

  void backward(){
    LeftMotorFront.Backward();
    RightMotorFront.Backward();
    LeftMotorRear.Backward();
    RightMotorRear.Backward();
  }

// void left(){
//   digitalWrite(LeftMotorFront1, LOW);
//   digitalWrite(RightMotorFront1, HIGH);
//   digitalWrite(LeftMotorFront2, LOW);
//   digitalWrite(RightMotorFront2, LOW);

//   digitalWrite(LeftMotorRear1, HIGH);
//   digitalWrite(RightMotorRear1, HIGH);
//   digitalWrite(LeftMotorRear2, LOW);
//   digitalWrite(RightMotorRear2, LOW);
// }

  void left(){
    LeftMotorFront.Backward();
    LeftMotorRear.Backward();
    RightMotorFront.Forward();
    RightMotorRear.Forward();
  }

  void right(){
    LeftMotorFront.Forward();
    LeftMotorRear.Forward();
    RightMotorFront.Backward();
    RightMotorRear.Backward();
  }

// void stop(){
//   digitalWrite(LeftMotorFront1, LOW);
//   digitalWrite(RightMotorFront1, LOW);
//   digitalWrite(LeftMotorFront2, LOW);
//   digitalWrite(RightMotorFront2, LOW);

//   digitalWrite(LeftMotorRear1, LOW);
//   digitalWrite(RightMotorRear1, LOW);
//   digitalWrite(LeftMotorRear2, LOW);
//   digitalWrite(RightMotorRear2, LOW);
// }

  void stop(){
    LeftMotorFront.Stop();
    LeftMotorRear.Stop();
    RightMotorFront.Stop();
    RightMotorRear.Stop();
  }


void loop() {
  // put your main code here, to run repeatedly:
  //forward();
  //delay(2000);
  //backward();
  //delay(2000);
  //stop();
  //delay(4000);
  right();
  delay(1000);
  stop();
  delay(3000);
}