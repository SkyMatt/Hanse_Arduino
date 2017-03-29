#ifndef Hanse_h
#define Hanse_h

class Igralec
{
int stanje;
int gumb;
public:
   Igralec();
   void rezultat(Igralec drugi);
   int stanjeO();
   void vnos(int st);
};



#endif