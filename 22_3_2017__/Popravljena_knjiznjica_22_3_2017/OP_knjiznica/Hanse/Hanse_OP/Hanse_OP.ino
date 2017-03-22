#include <Hanse.h>

int buttons[]={16,17,18,19};//deklaracija pinou za vnos
int vrednost[2];//shranjevanje vrednosti za funkcijo Igraled::vnos(int st) ---- st za 1. igralca=0,1;
                                                                              //st za 2. igralca=2,3;

void setup() {
  // put your setup code here, to run once:
for(int i=16;i<20;i++)
{
  pinMode(i, INPUT);
digitalWrite(i, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
Igralec metod;
metod.vnos(0);
metod.izpis();

}
