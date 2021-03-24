#define Pin_poten A0

int sensor_poten = 0;
int pulsador_1 = 0;
int pulsador_2 = 0;
int pulsador = 0;

void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);

 pinMode(11,OUTPUT); //luz led
 pinMode(6,INPUT);  //pulsador de activacion
 pinMode(7,INPUT);  //pulsador de desactivacion
 pinMode(8,OUTPUT); //Chicharra
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_poten = analogRead(Pin_poten);
  sensor_poten = sensor_poten/98;
  
  pulsador_1 = digitalRead(6);
  Serial.println("Tiempo");
  Serial.println(sensor_poten);
  delay(300);
  
  if ( pulsador_1 == 1)
  {
    pulsador = 1;
    delay(sensor_poten*1000);
    for ( int i = 0; i <= 1000; i++)
    {
      digitalWrite(8,HIGH);
      delay(1);
      digitalWrite(8,LOW);
      delay(1);
    }
    while( pulsador == 1)
    {
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);

      pulsador_2 = digitalRead(7);
      Serial.println(pulsador_2);
      
      if( pulsador_2 == 1 )
      {
        pulsador = 0;
      }
    }
    
  }
}
