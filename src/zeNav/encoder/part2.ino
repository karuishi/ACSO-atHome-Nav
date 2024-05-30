//define os pins do encoder
#define ENCA 2 //YELLOW
#define ENCB 3 //WHITE

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
    Serial.println(pos); //informa a posição atual
}

void readEncoder(){
    int b = digitalRead(ENCB); //le o output do encoder b
    if(b>0){ //caso sentido horário, o sinal de b será HIGH e engatilhará o interrupt 
        pos++; // adiciona 1 à posição
    } else { // caso sentido anti-horário, o sinal de b será LOW
        pos--; // remove 1 da posição
    }
}

