#define Pinmicro A0

int microfono = 0;
int chicharra = 8;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(chicharra,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  microfono = analogRead(Pinmicro);

  if(microfono > 100)
  {
    digitalWrite(chicharra,LOW);
    delay(1);
    digitalWrite(chicharra,HIGH);
    delay(1);
    microfono = analogRead(Pinmicro);
    if(microfono < 100)
    {
    delay(1000);
    digitalWrite(chicharra,LOW);
    }
  }
    


  


}
