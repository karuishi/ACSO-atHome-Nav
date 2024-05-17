#define LeftMotorFront1 26
#define LeftMotorFront2 25

#define LeftMotorRear1 17
#define LeftMotorRear2 16

#define RightMotorFront1 19
#define RightMotorFront2 18

#define RightMotorRear1 12
#define RightMotorRear2 27


#define HIGH 100

void setup() {
  // put your setup code here, to run once:
  pinMode(LeftMotorFront1, OUTPUT);
  pinMode(LeftMotorFront2, OUTPUT);

  pinMode(LeftMotorRear1, OUTPUT);
  pinMode(LeftMotorRear2, OUTPUT);

  pinMode(RightMotorFront1, OUTPUT);
  pinMode(RightMotorFront2, OUTPUT);

  pinMode(RightMotorRear1, OUTPUT);
  pinMode(RightMotorRear2, OUTPUT);

  pinMode(3, OUTPUT);
  analogWrite(3, LOW);

}
  void forward(){
  digitalWrite(LeftMotorFront1, HIGH);
  digitalWrite(RightMotorFront1, HIGH);
  digitalWrite(LeftMotorFront2, LOW);
  digitalWrite(RightMotorFront2, LOW);

  digitalWrite(LeftMotorRear1, HIGH);
  digitalWrite(RightMotorRear1, HIGH);
  digitalWrite(LeftMotorRear2, LOW);
  digitalWrite(RightMotorRear2, LOW);
  }

void backward(){
  digitalWrite(LeftMotorFront1, LOW);
  digitalWrite(RightMotorFront1, LOW);
  digitalWrite(LeftMotorFront2, HIGH);
  digitalWrite(RightMotorFront2, HIGH);

  digitalWrite(LeftMotorRear1, LOW);
  digitalWrite(RightMotorRear1, LOW);
  digitalWrite(LeftMotorRear2, HIGH);
  digitalWrite(RightMotorRear2, HIGH);
}

void left(){
  digitalWrite(LeftMotorFront1, LOW);
  digitalWrite(RightMotorFront1, HIGH);
  digitalWrite(LeftMotorFront2, LOW);
  digitalWrite(RightMotorFront2, LOW);

  digitalWrite(LeftMotorRear1, HIGH);
  digitalWrite(RightMotorRear1, HIGH);
  digitalWrite(LeftMotorRear2, LOW);
  digitalWrite(RightMotorRear2, LOW);
}

void stop(){
  digitalWrite(LeftMotorFront1, LOW);
  digitalWrite(RightMotorFront1, LOW);
  digitalWrite(LeftMotorFront2, LOW);
  digitalWrite(RightMotorFront2, LOW);

  digitalWrite(LeftMotorRear1, LOW);
  digitalWrite(RightMotorRear1, LOW);
  digitalWrite(LeftMotorRear2, LOW);
  digitalWrite(RightMotorRear2, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  forward();
  delay(2000);
  backward();
  delay(2000);
  stop();
  delay(4000);
  left();
  delay(1000);
  stop();
  delay(3000);
}