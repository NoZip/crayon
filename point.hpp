#ifndef POINT
#define POINT

class Point {
 public:
  static Point from_polar(float theta, float r);

  Point();
  Point(float x, float y);

  float get_x() const;
  float get_y() const;
  float get_theta() const;
  float get_r() const;

 protected:
  float _x;
  float _y;
};

// Point operator+(const Point &p1, const Point &p2);

#endif
