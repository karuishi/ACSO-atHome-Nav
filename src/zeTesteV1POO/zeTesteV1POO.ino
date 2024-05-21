#define HIGH 100 // 0 - 255

class DCMotor {
    int pin1, pin2;

    public:
        //void Pinout(int in1, int in2, int en) { // Pinout é o método para a declaração dos pinos que vão controlar o objeto motor
        void PinOut(int in1, int in2){
            pin1 = in1;
            pin2 = in2;

            pinMode(pin1, OUTPUT);
            pinMode(pin2, OUTPUT);
        }

        // Forward é o método para fazer o motor girar para frente
        void Forward(){
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
        }

        // Backward é o método para fazer o motor girar para trás
        void Backward(){
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
        }

        // Stop é o metodo para fazer o motor ficar parado.
        void Stop(){
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
        }
};

// Criação de quatro objetos motores, já que usaremos quatro motores, e eles já estão prontos para receber os comandos já configurados acima.
DCMotor LeftMotorFront, LeftMotorRear, RightMotorFront, RightMotorRear;

void setup(){
  LeftMotorFront.PinOut(26, 25); // Seleção dos pinos que cada motor usará, como descrito na classe.
  LeftMotorRear.PinOut(17, 16); // Seleção dos pinos que cada motor usará, como descrito na classe.
  RightMotorFront.PinOut(19, 18); // Seleção dos pinos que cada motor usará, como descrito na classe.
  RightMotorRear.PinOut(12, 27);  // Seleção dos pinos que cada motor usará, como descrito na classe.

  Stop(); //Inicializa com o motor parado.
}

void stop(){
    LeftMotorFront.Stop(); // Comando para o motor parar
    LeftMotorRear.Stop(); // Comando para o motor parar
    RightMotorFront.Stop(); // Comando para o motor parar
    RightMotorRear.Stop(); // Comando para o motor parar
}

void forward(){
    LeftMotorFront.Forward();   // Comando para o motor ir para frente
    LeftMotorRear.Forward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();   // Comando para o motor ir para frente
}

void back(){
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();   // Comando para o motor ir para trás
    RightMotorFront.Backward(); // Comando para o motor ir para trás
    RightMotorRear.Backward();  // Comando para o motor ir para trás 
}

void left(){
    LeftMotorFront.Backward();  // Comando para o motor ir para trás
    LeftMotorRear.Backward();    // Comando para o motor ir para frente
    RightMotorFront.Forward();  // Comando para o motor ir para frente
    RightMotorRear.Forward();  // Comando para o motor ir para trá
}

void superLeft(){
    LeftMotorFront.Backward(); // Comando para o motor ir para trás
    LeftMotorRear.Forward(); // Comando para o motor ir para frente 
    RightMotorFront.Forward(); // Comando para o motor ir para frente
    RightMotorRear.Forward(); // Comando para o motor ir para trás
}

void loop(){
    // Loop para o Zé formar um quadrado ao andar
    forward();
    delay(1000);
    stop();
    delay(1000);

    superLeft();
    delay(750);
    stop();
    delay(1000);

    forward();
    delay(1000);
    stop();
    delay(1000);


    superLeft();
    delay(750);
    stop();
    delay(1000);

    forward();
    delay(1000);
    stop();
    delay(1000);

    superLeft();
    delay(750);
    stop();
    delay(1000);

    forward();
    delay(1000);
    stop();
    delay(1000);

    superLeft();
    delay(750);
    stop();
    delay(1000);
}