#include <cmath>
#include <cstdio>
#include <iostream>

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

void Point::set_x(float a){
  _x = a;
}

void Point::set_y(float a){
  _y = a;
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

Point Point::translate(Point v) {  
  Point t(this->get_x() + v.get_x() , this->get_y() + v.get_y());
  return t;
} 

Point Point::rotate(Point c, float angle) {
  float nx, ny;
  float x = this->get_x();
  float y = this->get_y();
  float cx = c.get_x();
  float cy = c.get_y();
  float theta = this->get_theta();
  float angle_rad = angle * M_PI / 180;
  if(c.get_x() == 0 && c.get_y() == 0){   //Rotation de centre (0,0)

    nx = x * cos(angle_rad) - y * sin(angle_rad);
    ny = x * sin(angle_rad) + y * cos (angle_rad);
    cout << "les nouvelles coordonnees sont x= " << nx << "et y =" << ny  << endl;
  } else {
    // nx = cos(angle_rad) * x - cos(angle_rad) * cx - sin(angle_rad) * y + sin(angle_rad) * cy + cx;    
    // ny = cos(angle_rad) * y - cos(angle_rad) * cy + sin(angle_rad) * x - sin(angle_rad) * cx + cy;

     nx = cos(angle_rad) * (x-cx) - sin(angle_rad) * (y-cy) + cx;
     ny = sin(angle_rad) * (x-cx) + cos(angle_rad) * (y-cy) + cy;
     cout << "les nouvelles coordonnees sont x= " << nx << "et y =" << ny  << endl;
  }
 
  Point t(nx,ny);
  return t;
}
