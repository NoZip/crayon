#ifndef POINT
#define POINT

#include <string>

#include "expression.hpp"
#include "environment.hpp"

using std::string;

class Point {
 public:
  // static Point from_polar(Expression *theta, Expression *r);
  Point();
  Point(float x, float y);
  
  float get_x() const;
  float get_y() const;
  // float get_theta() const;
  // float get_r() const;
  
  Point translate(Point v);
  Point rotate(Point c, float angle);

  Point operator+(const Point &p2);
  Point operator-(const Point &p2);
  Point operator*(const Point &p2);
  Point operator/(const Point &p2);

 protected:
  float _x;
  float _y;
};

// Point operator+(const Point &p1, const Point &p2);

#endif
