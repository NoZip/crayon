#ifndef POINT
#define POINT

#include <string>

using std::string;

class Point {
 public:
  static Point from_polar(float theta, float r);

  Point();
  Point(float x, float y);

  string to_tmp_variable();
  string to_variable_affectation(string name);
  
  Point translate(Point v);
  Point rotate(Point c, float angle);
  float get_x() const;
  float get_y() const;
  float get_theta() const;
  float get_r() const;

 protected:
  float _x;
  float _y;
  void set_x(float a);
  void set_y(float a);
};

// Point operator+(const Point &p1, const Point &p2);

#endif
