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

int Environment::deep() {
  int d = 0;

  if (_parent) {
    d = 1 + _parent->deep();
  }

  return d;
}

Variable Environment::get_variable(const string &name) {
  Variable var;

  try {
    var = _variables.at(name);
    cout << "variable " << name << " accessed " << deep() << endl;
  }
  catch (const std::out_of_range& e) {
    if (_parent) {
      var = _parent->get_variable(name);
    }
    else {
      throw VariableError(string("Not Defined"));
    }
  }

  return var;
}

void Environment::set_variable(const string &name, VariableType type, void *value, bool initialization) {
  if(initialization) {
    Variable v = {type, value};
    _variables[name] = v;
    cout << "variable " << name << " initialized " << deep() << endl;
  }
  else {
    if (_variables.find(name) != _variables.end()) {
      Variable v = {type, value};
      _variables[name] = v;
      cout << "variable " << name << " set " << deep() << endl;
    }
    else if (_parent) {
      _parent->set_variable(name, type, value);
    }
    else {
      throw VariableError(string("Not Defined"));
    }
  }
}

void Environment::clear() {
  _variables.clear();
}