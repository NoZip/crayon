#include "path.hpp"
#include "point.hpp"

using namespace std;

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
