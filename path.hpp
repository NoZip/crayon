#ifndef CHEMIN
#define CHEMIN

#include <string>
#include <list>

#include "point_expression.hpp"

using std::list;
using std::string;

class Path : public list<PointExpression*> {
 public:
  // Path(std::initializing_list<Point> l);

  void append(PointExpression *p); //appel push back
  void append_relative(PointExpression *p); //appel push back en l'additionnant avec le dernier
  void append_cycle(); //copier le premier element a la fin
};

#endif
