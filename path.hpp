#ifndef CHEMIN
#define CHEMIN

#include <list>
#include "point.hpp"

using namespace std;

class Chemin : public list<Point>{
 public:
  void append(const Point &p); //appel push back
  void append_relative(const Point &p); //appel push back en l'additionnant avec le dernier
  void append_cycle(const Point &p); //copier le premier element a la fin
 protected:
  
};

#endif
