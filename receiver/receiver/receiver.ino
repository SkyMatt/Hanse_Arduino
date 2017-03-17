//OBVEZNE KNJIŽNICE IN OBJEKT/////
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

//////////////////////////////////
const byte rxAddr[6] = "00001";

void setup()
{
  Serial.begin(9600);//če rabš serijsko komunikacijo
  
  radio.begin();//zagon modula
  radio.openReadingPipe(0, rxAddr);//ker ima 0, je sprejemnik??
  
  radio.startListening();//vklop prejemanja podatkov
}

void loop()
{
  if (radio.available())// če smo prejeli podatke =1 -> drugače =0
  {
    char text[32] = {0};//če dobimo podatke naredimo char tabelo
    radio.read(&text, sizeof(text));//za branje prejetih podatkov
    Serial.println(text);
  }
}
