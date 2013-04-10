#ifndef POINT
#define POINT

class Point{
 public:
  Point();
  Point(float x, float y);
  ~Point();
  float get_x() const;
  float get_y() const;
 private:
  float _x;
  float _y;
};

#endif
