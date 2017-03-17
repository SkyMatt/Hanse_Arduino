#include <SPI.h> //za komunikacijski interface z modemom
#include <nRF24L01.h>// za driver tega radio modema
#include <RF24.h> // kontroliranje radio modema

RF24 radio(7, 8); //nov objekt knjižnice

const byte rxAddr[6] = "00001"; //globalna tabela rxAddr->naslov modema
                                //da se loči od ostalih wifi modemov
void setup()
{
  radio.begin();//zagon modema
  radio.setRetries(15, 15);//število ponovitev v primeru nepopolnega prenosa
  radio.openWritingPipe(rxAddr);//naslov prejemnika, kamor so pošljeni podatki
  
  radio.stopListening();//preklop iz ukaznega načina na podatkovno pošiljanje
}

void loop()
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));//pošiljanje na modem.
  //dokler radio.write() ne dobi potrditve ali pa je konec poskusov
  //se program blokira.
  
  delay(1000);
}
