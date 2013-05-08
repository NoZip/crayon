#include <stdexcept>
#include <iostream>

#include "error.hpp"

#include "environment.hpp"

#include "point.hpp"
#include "path.hpp"
#include "expression.hpp"

using namespace std;

Environment::Environment() {
  _parent = NULL;
  // set_variable(string("test"), SCALAR, new float(100.0));
}

Environment::Environment(Environment *parent) {
  _parent = parent;
}

Environment::~Environment() {
  
}

Environment* Environment::get_parent() {
  return _parent;
}

Variable Environment::get_variable(const string &name) {
  try {
    return _variables.at(name);
  }
  catch (const std::out_of_range& e) {
    if (_parent) {
      return _parent->get_variable(name);
    }
    else {
      throw VariableError(string("Not Defined"));
    }
  }
}

void Environment::set_variable(const string &name, VariableType type, void *value) {
  cout << "variable " << name << " set" << endl;
  Variable v = {type, value};
  _variables[name] = v;
}


