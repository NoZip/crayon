#ifndef POINT
#define POINT

#include <string>

#include "expression.hpp"
#include "environment.hpp"

using std::string;

class Point {
 public:
  // static Point from_polar(float theta, float r);

  Point(Expression *x, Expression *y);
  
  float get_x(Environment &env) const;
  float get_y(Environment &env) const;
  // float get_theta() const;
  // float get_r() const;

  Expression* get_x_expression() const;
  Expression* get_y_expression() const;
  
  // Point translate(Point v);
  // Point rotate(Point c, float angle);

 protected:
  Expression *_x;
  Expression *_y;
};

// Point operator+(const Point &p1, const Point &p2);

#endif
