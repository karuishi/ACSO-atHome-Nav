/*
    Programa Teste Rotary Encoder 

    * Criado por Cleber Borges - Funbots - @cleber.funbots *
    * Adaptado por Pedro Lucas - ACSO - pedrolucas.js18@gmail.com * 
*/

#include <wire.h>

#define LeftMotorFront 26
#define RightMotorFront 19

int cont = 0;
int estadoAtualL;
int estadoAnteriorL;

char sentido[] = " ";

void setup(){
    //configura pinos encoder como entrada
    pinMode(LeftMotorFront, INPUT);
    pinMode(RightMotorFront, INPUT);

    //le estado atual do pino L
    estadoAtualL = digitalRead(LeftMotorFront);

}

void loop(){
    //le estado atual do pino L
    estadoAtualL = digitalWrite(LeftMotorFront);

    //se estado atual for diferente do anterior, houve um pulso
    if(estadoAtualL != estadoAnteriorL){
        //se R for diferente, então ele gira no sentido horário
        if(digitalRead(RightMotorFront) != estadoAtualL){
            cont--;
            sentido = "Horário";
        } else {
            //senão ele gira no sentido anti-horário
            cont++;
            sentido = "Anti-horário";
        }   

    Serial.print("valor: ");
    Serial.print(cont);

    //limpa display de digitos antigos
    if(cont < 100 && cont >=0){
        if(cont <10 && cont >= 0){
            Serial.print(" ");
        } else {
            Serial.print(" ");
        }
    } 

    if(cont < -100 && cont <= 0){
        if(cont -10 && cont <=0){
            Serial.print(" ");
        } else {
            Serial.print(" ");
        }
    }

    Serial.print("Sentido: ");
    Serial.print(sentido);
    }
    estadoAnteriorL = estadoAtualL;
}