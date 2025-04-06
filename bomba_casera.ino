
#include <Arduino.h>
// Pines de los sensores

const int sensorMinimoRecipiente5 = 44;
const int sensorMaximoRecipiente5 = 45;
const int sensorMinimoRecipiente4 = 46;
const int sensorMaximoRecipiente4 = 47;
const int sensorMinimoRecipiente3 = 48;
const int sensorMaximoRecipiente3 = 49;
const int sensorMinimoRecipiente2 = 50;
const int sensorMaximoRecipiente2 = 51;
const int sensorMinimoRecipiente1 = 52;
const int sensorMaximoRecipiente1 = 53;

// Pines de la bomba y el LED
const int bombaAgua = 2;
const int ledError = 41;

const int recipiente1 = 7;
const int recipiente2 = 6;
const int recipiente3 = 5;
const int recipiente4 = 4;
const int recipiente5 = 3;
// const int recipiente6 = 2;

int bombaActiva = 0;
bool valvulaRecipiente1Activa = 0;
bool valvulaRecipiente2Activa = 0;
bool valvulaRecipiente3Activa = 0;
bool valvulaRecipiente4Activa = 0;
bool valvulaRecipiente5Activa = 0;
 
int arregloDeValvulas[5] = {0, 0, 0, 0, 0};

void setup()
{
    // Configuración de pines
    pinMode(sensorMinimoRecipiente1, INPUT);
    pinMode(sensorMaximoRecipiente1, INPUT);
    pinMode(sensorMinimoRecipiente2, INPUT);
    pinMode(sensorMaximoRecipiente2, INPUT);
    pinMode(sensorMinimoRecipiente3, INPUT);
    pinMode(sensorMaximoRecipiente3, INPUT);
    pinMode(bombaAgua, OUTPUT);
    pinMode(ledError, OUTPUT);
    pinMode(recipiente1, OUTPUT);
    pinMode(recipiente2, OUTPUT);
    pinMode(recipiente3, OUTPUT);
    pinMode(recipiente4, OUTPUT);
    pinMode(recipiente5, OUTPUT);

    // pinMode(bomba6, OUTPUT);

    // Inicializa la bomba y el LED apagados
    digitalWrite(bombaAgua, LOW);
    digitalWrite(ledError, LOW);
    digitalWrite(recipiente1, LOW);
    digitalWrite(recipiente2, LOW);
    digitalWrite(recipiente3, LOW);
    digitalWrite(recipiente4, LOW);
    digitalWrite(recipiente5, LOW);
    // digitalWrite(bomba6, LOW);

    // Inicializa la comunicación serie
    Serial.begin(9600);
}

void loop()
{
    // Lee el estado de los sensores
    bool nivelMinimoRecipiente1 = digitalRead(sensorMinimoRecipiente1);
    bool nivelMaximoRecipiente1 = digitalRead(sensorMaximoRecipiente1);
    bool nivelMinimoRecipiente2 = digitalRead(sensorMinimoRecipiente2);
    bool nivelMaximoRecipiente2 = digitalRead(sensorMaximoRecipiente2);
    bool nivelMinimoRecipiente3 = digitalRead(sensorMinimoRecipiente3);
    bool nivelMaximoRecipiente3 = digitalRead(sensorMaximoRecipiente3);
    bool nivelMinimoRecipiente4 = digitalRead(sensorMinimoRecipiente4);
    bool nivelMaximoRecipiente4 = digitalRead(sensorMaximoRecipiente4);
    bool nivelMinimoRecipiente5 = digitalRead(sensorMinimoRecipiente5);
    bool nivelMaximoRecipiente5 = digitalRead(sensorMaximoRecipiente5);
    

    if(nivelMinimoRecipiente1 == false && nivelMaximoRecipiente1 == false){
      arregloDeValvulas[0] = 1;
      bombaActiva = 1;
      valvulaRecipiente1Activa = 1;
      valvulaRecipiente2Activa = 0;
      valvulaRecipiente3Activa = 0;
      valvulaRecipiente4Activa = 0;
      valvulaRecipiente5Activa = 0;
    }
    if(nivelMinimoRecipiente2 == false && nivelMaximoRecipiente2 == false){
      arregloDeValvulas[1] = 1;
      bombaActiva = 1;
      valvulaRecipiente1Activa = 0;
      valvulaRecipiente2Activa = 1;
      valvulaRecipiente3Activa = 0;
      valvulaRecipiente4Activa = 0;
      valvulaRecipiente5Activa = 0;
    }
    if(nivelMinimoRecipiente3 == false && nivelMaximoRecipiente3 == false){
      arregloDeValvulas[2] = 1;
      bombaActiva = 1;
      valvulaRecipiente1Activa = 0;
      valvulaRecipiente2Activa = 0;
      valvulaRecipiente3Activa = 1;
      valvulaRecipiente4Activa = 0;
      valvulaRecipiente5Activa = 0;
    }
    if(nivelMinimoRecipiente4 == false && nivelMaximoRecipiente4 == false){
      arregloDeValvulas[3] = 1;
      bombaActiva = 1;
      valvulaRecipiente1Activa = 0;
      valvulaRecipiente2Activa = 0;
      valvulaRecipiente3Activa = 0;
      valvulaRecipiente4Activa = 1;
      valvulaRecipiente5Activa = 0;
    }
    if(nivelMinimoRecipiente5 == false && nivelMaximoRecipiente5 == false){
      arregloDeValvulas[3] = 0;
      arregloDeValvulas[4] = 1;
      bombaActiva = 1;
      valvulaRecipiente1Activa = 0;
      valvulaRecipiente2Activa = 0;
      valvulaRecipiente3Activa = 0;
      valvulaRecipiente4Activa = 0;
      valvulaRecipiente5Activa = 1;
    }
    if(
      nivelMinimoRecipiente5 == true && nivelMaximoRecipiente5 == true &&
      nivelMinimoRecipiente4 == true && nivelMaximoRecipiente4 == true &&
      nivelMinimoRecipiente3 == true && nivelMaximoRecipiente3 == true &&
      nivelMinimoRecipiente2 == true && nivelMaximoRecipiente2 == true &&
      nivelMinimoRecipiente1 == true && nivelMaximoRecipiente1 == true 
      ){
        bombaActiva = 0;
        valvulaRecipiente1Activa = 0;
      valvulaRecipiente2Activa = 0;
      valvulaRecipiente3Activa = 0;
      valvulaRecipiente4Activa = 0;
      valvulaRecipiente5Activa = 0;
      }
    
    digitalWrite(bombaAgua, bombaActiva);
    digitalWrite(recipiente1, valvulaRecipiente1Activa);
    digitalWrite(recipiente2, valvulaRecipiente2Activa);
    digitalWrite(recipiente3, valvulaRecipiente3Activa);
    digitalWrite(recipiente4, valvulaRecipiente4Activa);
    digitalWrite(recipiente5, valvulaRecipiente5Activa);
    // Serial.print("Recipiente UNO Min:  ");
    // Serial.print(nivelMinimoRecipiente1);
    // Serial.print(" max:  ");
    // Serial.println(nivelMaximoRecipiente1);
    Serial.print("Bomba:" );
    Serial.println(bombaActiva);    
    Serial.print("Arreglo de bombas:" );
    Serial.print(arregloDeValvulas[0]);   
    Serial.print(arregloDeValvulas[1]); 
    Serial.print(arregloDeValvulas[2]);   
    Serial.print(arregloDeValvulas[3]);   
    Serial.print(arregloDeValvulas[4]);   


    //", nivelMinimoRecipiente1 ," max: ",nivelMaximoRecipiente1
    // Espera 500 ms antes de la siguiente lectura
    delay(500);
}