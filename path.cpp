#include "path.hpp"
#include "point.hpp"

using namespace std;

string Path::to_tmp_variable() const {
  string s;

  s.append("{");

  for (auto it = begin(); it != end(); ++it) {
    if (it != begin()) {
      s.append(",");
    }
    
    s.append(it->to_tmp_variable());
  }

  s.append("}");

  return s;
}

string Path::to_variable_affectation(string name) const {
  string s;

  // s.append("Path ");
  // s.append(name);
  // s.append(" = ");
  // s.append(to_tmp_variable());
  // s.append(";");

  s += "Path " + name + " = " + to_tmp_variable() + ";";

  return s;
}

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
