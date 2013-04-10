#include "point.hpp"

using namespace std;

Point::Point(){
  _x = 0; _y = 0;
}

Point::Point(float x, float y){
  _x = x; _y =y;
}

float Point::get_x() const{
  return _x;
}

float Point::get_y() const{
  return _y;
}

Point::~Point(){}
