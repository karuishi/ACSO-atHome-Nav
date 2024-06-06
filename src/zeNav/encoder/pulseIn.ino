int pinoEncoder = 4;
int pinoMotor1 = 19;
int pinoMotor2 = 18;

int pulso;

void setup(){
    Serial.begin(9600);
    pinMode(pinoEncoder, OUTPUT);
    pinMode(pinoMotor1, OUTPUT);
    pinMode(pinoMotor2, OUTPUT);

    digitalWrite(pinoMotor1, LOW);
    digitalWrite(pinoMotor2, LOW);
}

void loop(){
    delay(500);
    digitalWrite(pinoMotor1, HIGH);
    digitalWrite(pinoMotor2, LOW);
    delay(2000);

    digitalWrite(pinoMotor1, LOW);
    digitalWrite(pinoMotor2, HIGH);
    delay(2000);

    if(digitalRead(pinoMotor1) == HIGH){
        digitalWrite(pinoEncoder, HIGH);
        pulso++;
    } else {
        digitalWrite(pinoEncoder, LOW);
        pulso--;
    }
    
    Serial.println("Pulsos: ");
    Serial.println(pulso);
}