#ifndef CHEMIN
#define CHEMIN

#include <string>
#include <list>

#include "point.hpp"

using std::list;
using std::string;

class Path : public list<Point> {
 public:
  // Path(std::initializing_list<Point> l);

  void append(const Point &p); //appel push back
  void append_relative(const Point &p); //appel push back en l'additionnant avec le dernier
  void append_cycle(); //copier le premier element a la fin
};

#endif
