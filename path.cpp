#include "path.hpp"
#include "point.hpp"

using namespace std;


void Path::append(const Point &p){
  this->push_back(p);
}

void Path::append_relative(const Point &p){
  Expression *tmp_x = new BinaryExpression(EXPR_PLUS, back().get_x_expression(), p.get_x_expression());
  Expression *tmp_y = new BinaryExpression(EXPR_PLUS, back().get_y_expression(), p.get_y_expression());
  this->push_back(Point(tmp_x, tmp_y));
}

void Path::append_cycle(){
  this->push_back(front());
}
