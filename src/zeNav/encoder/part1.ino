//define os pins do encoder
#define ENCA 2 //YELLOW
#define ENCB 3 //WHITE

void setup(){
    Serial.begin(9600);
    //modo de leitura dos pins
    pinMode(ENCA, INPUT);
    pinMode(ENCB, INPUT);
}

void loop(){
    //le os pins do encoder
    int a = digitalRead(ENCA);
    int b = digitalRead(ENCB);
    //printa os valores do encoder a e b
    // a = sentido horário e b = sentido anti-horário
    Serial.print(a*5);
    Serial.print(" ");
    Serial.print(b*5);
    Serial.println();
}

