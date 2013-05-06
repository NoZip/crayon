#include "path.hpp"
#include "point.hpp"

using namespace std;

string Path::to_tmp_variable() {
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

string Path::to_variable_affectation(string name) {
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
  Point tmp(back().get_x() + p.get_x(), back().get_y() + p.get_y()); //on cree un nouveau point en additionnant celui de la fin de la liste et celui en parametre
  this->push_back(tmp);
}

void Path::append_cycle(){
  this->push_back(front());
}
