#include <cmath>
#include <cstdio>
#include <iostream>

#include "point.hpp"

using namespace std;

// Point Point::from_polar(Expression *theta, Expression *r) {
//   Expression *x_expr = new BinaryExpression(EXPR_MUL, r, new UnaryExpression(EXPR_COS, theta));
//   Expression *y_expr = new BinaryExpression(EXPR_MUL, r, new UnaryExpression(EXPR_SIN, theta));
//   return Point(x_expr, y_expr);
// }

Point::Point(){
  _x = 0.0;
  _y = 0.0;
}

Point::Point(float x, float y) {
  _x = x;
  _y = y;
}

float Point::get_x() const {
  return _x;
}

float Point::get_y() const {
  return _y;
}

// float Point::get_theta() const {
//   return atan2(get_y(), get_x());
// }

// float Point::get_r() const {
//   float x = get_x();
//   float y = get_y();
//   return sqrt(x * x + y * y);
// }

Point Point::translate(Point v) { 
  return Point(_x + v._x, _y + v._y);
} 

Point Point::rotate(Point p, float angle) {
  float angle_rad = angle * M_PI /180;
  double x = p._x * cos(angle_rad) - p._y * sin(angle_rad);
  double y = p._x * sin(angle_rad) + p._y * cos(angle_rad);
  return *(new Point(x, y));

  /*
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
  return t;*/
}

Point Point::operator+(const Point &p2){
  return Point(_x + p2._x, _y + p2._y);
}

Point Point::operator-(const Point &p2){
  return Point(_x - p2._x, _y - p2._y);
}

Point Point::operator*(const Point &p2){
  return Point(_x * p2._x, _y * p2._y);
}

Point Point::operator/(const Point &p2){
  return Point(_x / p2._x, _y / p2._y);
}
