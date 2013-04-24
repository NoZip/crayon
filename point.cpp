#include <cmath>
#include <cstdio>

#include "point.hpp"

using namespace std;

Point Point::from_polar(float theta, float r) {
  Point p(r * cos(theta), r * sin(theta));
  return p;
}

Point::Point(){
  _x = 0;
  _y = 0;
}

Point::Point(float x, float y){
  _x = x;
  _y =y;
}

float Point::get_x() const {
  return _x;
}

float Point::get_y() const {
  return _y;
}

float Point::get_theta() const {
  return atan2(_y, _x);
}

float Point::get_r() const {
  return sqrt(_x * _x + _y * _y);
}

string Point::to_string() {
  char s[32];
  sprintf(s, "(%f, %f)", _x, _y);
  return string(s);
}
