#include "Hanse.h"
#include "Arduino.h"

Igralec::Igralec(){stanje=0;}


void Igralec::rezultat(Igralec drugi)
{
       if(gumb==1 && drugi.gumb==1) // če sta oba sodelovala
       {
        stanje+=1;
        drugi.stanje+=1;
       }
       else if(gumb==1 && drugi.gumb==0)
       {
        stanje-=1;
        drugi.stanje+=1;

       }
       else if(gumb==0 && drugi.gumb==1)
       {
       stanje+=1;
       drugi.stanje-=1;
       }
       else{stanje-=1;drugi.stanje-=1;}// v primeru da obe NE sodelujeta
   }

int Igralec::stanjeO(){return stanje;}//vračanje stanja

int buttons[]={16,17,18,19};//deklaracija pinou za vnos
int vrednost[2];//shranjevanje vrednosti za funkcijo Igraled::vnos(int st) ---- st za 1. igralca=0,1;
                                                                              //st za 2. igralca=2,3;
void Igralec::vnos(int st)
{
vrednost[0]=(digitalRead(buttons[st])); //__NE
vrednost[1]=(digitalRead(buttons[st+1])); //__DA
if(vrednost[0]==1 && vrednost[1]==0)
{gumb=1;}
else if(vrednost[0]==0 && vrednost[1]==1)
{gumb=0;}
else
{
  vnos(st);
  }
}
