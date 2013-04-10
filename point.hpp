#ifndef POINT
#define POINT

class Point{
 public:
  Point();
  Point(float x, float y);
  Point(Angle theta, double r);
  ~Point();
  float get_x() const;
  float get_y() const;
 private:
  float _x;
  float _y;
  float x_from_polar(Angle theta, double r);
  float y_from_polar(Angle theta, double r);
};

Point operator+(Point p1, Point p2);

#endif
