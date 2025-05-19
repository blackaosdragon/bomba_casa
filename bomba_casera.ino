
#include <Arduino.h>
// Pines de los sensores
// cambio a repositorio publico

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

const int sensorPrincipalBajo = 8;
const int sensorPrincipalMedio = 9;
const int sensorPrincipalLleno = 10;

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
int numeroCiclo = 0;
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
  pinMode(sensorPrincipalBajo, INPUT);
  pinMode(sensorPrincipalMedio, INPUT);
  pinMode(sensorPrincipalLleno, INPUT);

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
  bombaActiva = 0;
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
  bool nivelSensorPrincipalVacio = digitalRead(sensorPrincipalBajo);
  bool nivelSensorPrincipalMedio = digitalRead(sensorPrincipalMedio);
  bool nivelSensorPrincipalLleno = digitalRead(sensorPrincipalLleno);

  if (nivelMinimoRecipiente1 == false)
  {
    arregloDeValvulas[0] = 1;
  }
  if (nivelMaximoRecipiente1 == true)
  {
    arregloDeValvulas[0] = 0;
  }
  if (nivelMinimoRecipiente2 == false)
  {
    arregloDeValvulas[1] = 1;
  }
  if (nivelMaximoRecipiente2 == true)
  {
    arregloDeValvulas[1] = 0;
  }
  if (nivelMinimoRecipiente3 == false)
  {
    arregloDeValvulas[2] = 1;
  }
  if (nivelMaximoRecipiente3 == true)
  {
    arregloDeValvulas[2] = 0;
  }
  if (nivelMinimoRecipiente4 == false)
  {
    arregloDeValvulas[3] = 1;
  }
  if (nivelMaximoRecipiente4 == true)
  {
    arregloDeValvulas[3] = 0;
  }
  if (nivelMinimoRecipiente5 == false)
  {
    arregloDeValvulas[4] = 1;
  }
  if (nivelMaximoRecipiente5 == true)
  {
    arregloDeValvulas[4] = 0;
  }
  Serial.print("Tanque 1: Min: ");
  Serial.print(nivelMinimoRecipiente1);
  Serial.print("Max: ");
  Serial.print(nivelMaximoRecipiente1);
  Serial.print(" / ");

  if (numeroCiclo == 0)
  {
    if (nivelMinimoRecipiente1 == false)
    {
      valvulaRecipiente1Activa = true;
    }
    if (nivelMaximoRecipiente1 == true)
    {
      valvulaRecipiente1Activa = false;
      numeroCiclo = numeroCiclo + 1;
    }
  }
  if (numeroCiclo == 1)
  {
    if (nivelMinimoRecipiente2 == false)
    {
      valvulaRecipiente2Activa = true;
    }
    if (nivelMaximoRecipiente2 == true)
    {
      valvulaRecipiente2Activa = false;
      numeroCiclo = numeroCiclo + 1;
    }
  }
  if (numeroCiclo == 2)
  {
    if (nivelMinimoRecipiente3 == false)
    {
      valvulaRecipiente3Activa = true;
    }
    if (nivelMaximoRecipiente3 == true)
    {
      valvulaRecipiente3Activa = false;
      numeroCiclo = numeroCiclo + 1;
    }
  }
  if (numeroCiclo == 3)
  {
    if (nivelMinimoRecipiente4 == false)
    {
      valvulaRecipiente4Activa = true;
    }
    if (nivelMaximoRecipiente4 == true)
    {
      valvulaRecipiente4Activa = false;
      numeroCiclo = numeroCiclo + 1;
    }
  }
  if (numeroCiclo == 4)
  {
    if (nivelMinimoRecipiente5 == false)
    {
      valvulaRecipiente5Activa = true;
    }
    if (nivelMaximoRecipiente5 == true)
    {
      valvulaRecipiente5Activa = false;
      numeroCiclo = numeroCiclo + 1;
    }
  }

  if (nivelSensorPrincipalVacio == true && nivelSensorPrincipalMedio == true && nivelSensorPrincipalLleno == true)
  {
    bombaActiva = 1;
  }
  if (nivelSensorPrincipalVacio == false)
  {
    bombaActiva = 0;
  }
  if (valvulaRecipiente5Activa == false && valvulaRecipiente4Activa == false && valvulaRecipiente3Activa == false && valvulaRecipiente2Activa == false && valvulaRecipiente1Activa == false)
  {
    bombaActiva = 0;
  }
  // Serial.print("arregloDeValvulas:" );
  // Serial.print(arregloDeValvulas[numeroCiclo]);
  Serial.print(" ");
  Serial.print("numeroCiclo: ");
  Serial.print(numeroCiclo);
  Serial.print(" ");
  // numeroCiclo = numeroCiclo+1;

  if (numeroCiclo >= 5)
  {
    numeroCiclo = 0;
  }
  // arregloDeValvulas[5] = {0, 0, 0, 0, 0};

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
  Serial.print("Bomba:");
  Serial.println(bombaActiva);
  // Serial.print("Arreglo de bombas: ");
  Serial.print(arregloDeValvulas[0]);
  Serial.print(arregloDeValvulas[1]);
  Serial.print(arregloDeValvulas[2]);
  Serial.print(arregloDeValvulas[3]);
  Serial.print(arregloDeValvulas[4]);
  Serial.print(" ");

  //", nivelMinimoRecipiente1 ," max: ",nivelMaximoRecipiente1
  // Espera 500 ms antes de la siguiente lectura
  delay(1000);
}