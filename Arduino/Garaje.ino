#include<Servo.h>

#define piSensorA A0
#define piSensorB A1

Servo motor;

int sensorA = 0;
int sensorB = 0;
int LedFoco = 12;
int Buzzer = 7;
int duracionBuzzer = 7000;
int nota_Buzzer= 262;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);
  pinMode(LedFoco, OUTPUT);
  pinMode(9, OUTPUT);
  motor.attach(9);
  
}

void loop() {
  
  sensorA = analogRead(piSensorA);
  sensorB = analogRead(piSensorB);

  Serial.println(sensorA);

// Detectamos la entrada del vehiculo
  if (sensorB > 1000) {
    Serial.println(sensorA);
    digitalWrite(LedFoco, HIGH);
    delay(1000);    
    tone(Buzzer, nota_Buzzer, duracionBuzzer);
    cerrarPuerta();
  }

  // Cerrar puerta
  
  if (sensorA > 1000) {
    abrirPuerta();
    digitalWrite(LedFoco, LOW);
    delay(1000);
    
      
  }
}

void cerrarPuerta(){
  motor.write(90);
  delay(500);
    motor.write(80);
  delay(500);
    motor.write(70);
  delay(500);
    motor.write(60);
  delay(500);
    motor.write(50);
  delay(500);
    motor.write(40);
  delay(500);
    motor.write(30);
  delay(500);
    motor.write(20);
  delay(500);
  motor.write(10);
  delay(500);
  motor.write(0);
  delay(500);
  }

  void abrirPuerta(){
    motor.write(0);
  delay(500);
    motor.write(10);
  delay(500);
    motor.write(20);
  delay(500);
    motor.write(30);
  delay(500);
    motor.write(40);
  delay(500);
    motor.write(50);
  delay(500);
    motor.write(60);
  delay(500);
    motor.write(70);
  delay(500);
  motor.write(80);
  delay(500);
  motor.write(90);
  delay(500);
    }
