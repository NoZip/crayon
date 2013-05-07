#include <stdexcept>
#include <iostream>

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

void print_map(const map<string, Variable> &m) {
  std::cout << "MAP" << std::endl;
  for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << "Key=" << it->first << std::endl;
    Variable v = it->second;
    switch (v.type) {
      case SCALAR:
      std::cout << "Value=" << ((Expression*) it->second.value)->calculate() << std::endl;
      break;

      case VECTOR2D:
      std::cout << "Value=" << ((Point*) it->second.value)->to_tmp_variable() << std::endl;
      break;

      case PATH:
      std::cout << "Value=" << ((Path*) it->second.value)->to_tmp_variable() << std::endl;
      break;
    }

  }
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
      print_map(_variables);
      throw string("FUCk IT");
    }
  }
}

void Environment::set_variable(const string &name, VariableType type, void *value) {
  cout << "variable " << name << " set" << endl; 
  Variable v = {type, value};
  _variables[name] = v;
}


