#ifndef VARIABLE_AFFECTATION
#define VARIABLE_AFFECTATION

#include <string>

#include "instruction.hpp"
#include "environment.hpp"
#include "expression.hpp"

using std::string;

class VariableAffectation : public Instruction {
protected:
  string _name;
  Variable _value;

public:
  VariableAffectation(const string &name, VariableType type, Expression *value);
  virtual ~VariableAffectation();

  virtual void print();
  virtual void execute(Environment &env);
};

#endif