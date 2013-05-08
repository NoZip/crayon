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

class VariableIncrement : public Instruction {
protected:
	string _name;
	ExpressionOperator _op;
	Expression *_expr;

public:
  VariableIncrement(const string &name, ExpressionOperator op, Expression *value);
  virtual ~VariableIncrement();

  virtual void print();
  virtual void execute(Environment &env);
};

#endif