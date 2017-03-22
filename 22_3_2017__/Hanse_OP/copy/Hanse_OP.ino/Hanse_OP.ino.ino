#include <Hanse.h>




void setup() {
  // put your setup code here, to run once:
//(2 PIN GUMB) 1.pin ->GND, 2.pin -> PIN arduinota
Serial.begin(9600);

for(int i=16;i<20;i++) //deklaracija pinou za input (16,17,18,19)
{
  pinMode(i, INPUT);
digitalWrite(i, HIGH);
  }
}

int omejitev=0;

void loop() {
  // put your main code here, to run repeatedly:
Igralec metod;
Igralec denis;
Serial.print("Vstavi stevilo: ");
while(omejitev<=0){
omejitev=Serial.read()-48;
Serial.println(omejitev);
delay(500);}
Serial.println(omejitev);
do{
denis.vnos(0);
denis.izpis();
metod.vnos(2);
metod.izpis();
metod.rezultat(denis);
Serial.print("METOD: ");
Serial.println(metod.stanjeO());
Serial.print("DENIS: ");
Serial.println(denis.stanjeO());
}while(metod.stanjeO()<omejitev && denis.stanjeO()<omejitev);
if(metod.stanjeO()<denis.stanjeO())
{
  Serial.println("DENIS OP");
  Serial.println(denis.stanjeO());
  }
else {Serial.println("METOD OP");
Serial.println(metod.stanjeO());
}}

