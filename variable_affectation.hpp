#ifndef VARIABLE_AFFECTATION
#define VARIABLE_AFFECTATION

#include <string>

#include "instruction.hpp"
#include "environment.hpp"
#include "expression.hpp"

using std::string;


class VariableInitialization : public Instruction {
protected:
  string _name;
  Variable _value;

public:
  VariableInitialization(const string &name, VariableType type, void *value);
  virtual ~VariableInitialization();

  virtual void print();
  virtual void execute(Environment &env);
};

class VariableAffectation : public Instruction {
protected:
  string _name;
  Variable _value;

public:
  VariableAffectation(const string &name, VariableType type, void *value);
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