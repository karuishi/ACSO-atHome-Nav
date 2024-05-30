//define os pins do encoder e do motor
#define ENCA 2 //YELLOW
#define ENCB 3 //WHITE
#define IN1 7 // MOTOR-PONTE H 1
#define IN2 6 // MOTOR-PONTE H 2

int pos = 0; //posição do encoder

void setup(){
    Serial.begin(9600);
    pinMode(ENCA, INPUT); //modo de leitura do pin a
    pinMode(ENCB, INPUT); //modo de leitura do pin b
    attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING); //invés de ler o output do encoder, atribuimos uma função para interromper o fluxo assim que o output do a subir
    //ENCA = encoder output pin A
    //readEncoder = função chamada após o interrupt
    //RISING = o tipo do gatilho do sinal
}

void loop(){
    setMotor(1, IN1, IN2); //chamando a função com direção 1
    delay(200);
    Serial.println(pos); //informa a posição atual
    setMotor(-1, IN1, IN2); //chamando a função com direção 1
    delay(200);
    Serial.println(pos); //informa a posição atual
    setMotor(0, IN1, IN2); //chamando a função com direção 1
    delay(200);
    Serial.println(pos); //informa a posição atual
}

void setMotor(int dir, int in1, int in2){ //função para definir a direção e velocidade do motor
    int spd = 200; // define a velocidade 0-255
    if(dir == 1){ //se dir = 1, rotaciona em uma direção
        analogWrite(in1, spd);
        digitalWrite(in2, LOW);
    } else if(dir == -1){ //se dir = -1, rotaciona em outra direção
        digitalWrite(in1, LOW);
        analogWrite(in2, spd);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }
}

void readEncoder(){
    int b = digitalRead(ENCB); //le o output do encoder b
    if(b>0){ //caso sentido horário, o sinal de b será HIGH e engatilhará o interrupt 
        pos++; // adiciona 1 à posição
    } else { // caso sentido anti-horário, o sinal de b será LOW
        pos--; // remove 1 da posição
    }
}

