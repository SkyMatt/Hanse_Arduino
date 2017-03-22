#ifndef Hanse_h
#define Hanse_h

class Igralec
{
int stanje;
bool gumb;
public:
   Igralec();
   Igralec(const Igralec &drugi);
   void rezultat(Igralec drugi);
   void izpis();
   int stanjeO();
   void vnos(int st);
};



#endif