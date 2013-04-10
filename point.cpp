#include "point.hpp"

using namespace std;

Point::Point(){
  _x = 0; _y = 0;
}

Point::Point(float x, float y){
  _x = x; _y =y;
}

Point::Point(Angle theta, double r) {
 m_x = x_from_polar(theta, r);
 m_y = y_from_polar(theta,r);
}

float Point::get_x() const{
  return _x;
}

float Point::get_y() const{
  return _y;
}

float Point::x_from_polar(Angle theta, double r) {
   return r * cos(theta);
}

float Point::y_from_polar(Angle theta, double r) {
   return r * cos(theta);
}

Point::~Point(){}
