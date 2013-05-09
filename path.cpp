#include "path.hpp"
#include "point.hpp"

using namespace std;


void Path::append(PointExpression *p){
  this->push_back(p);
}

void Path::append_relative(PointExpression *p){
  this->push_back(new BinaryPointExpression(EXPR_PLUS, back(), p));
}

void Path::append_cycle(){
  this->push_back(front());
}
