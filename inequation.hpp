#ifndef INEQUATION
#define INEQUATION

#include <string>

#include "environment.hpp"
#include "expression.hpp"

using std::string;

enum InequationOperator {
  INEQ_EQUAL,
  INEQ_NEQUAL,
  INEQ_GT,
  INEQ_GTE,
  INEQ_LT,
  INEQ_LTE,
  INEQ_AND,
  INEQ_OR,
  INEQ_NOT
};

//classe permettant de calculer les inequations
class Inequation {
public:
  virtual ~Inequation();

  virtual bool calculate(Environment &env) = 0;
};

class ConstantInequation : public Inequation {
protected:
  bool _value;

public:
  ConstantInequation(bool value);
  virtual ~ConstantInequation();

  virtual bool calculate(Environment &env);
};

//**Au cas ou on veuille mettre des variables bool**//
//
// class VariableInequation : public Inequation {
// protected:
//   Environment *_env;
//   string _name;

// public:
//   VariableInequation(Environment *env, const string &name);
//   virtual ~VariableInequation();

//   virtual bool calculate(Environment &env);
// };

//Inequation unaire, par exemple "!variable"
class UnaryInequation : public Inequation {
protected:
  InequationOperator _op;
  Inequation *_expr;

public:
  UnaryInequation(InequationOperator op, Inequation *expr);
  virtual ~UnaryInequation();

  virtual bool calculate(Environment &env);
};

//Inequation binaire, par exemple "var1 < var2"
class BinaryInequation : public Inequation {
protected:
  InequationOperator _op;
  Expression *_expr1;
  Expression *_expr2;

public:
  BinaryInequation(InequationOperator op, Expression *expr1, Expression *expr2);
  virtual ~BinaryInequation();

  virtual bool calculate(Environment &env);
};

//Pour composer des inequations avec && et ||
//exemple "var1 < var2 && var3 < var4"
class CompositeInequation : public Inequation {
protected:
  InequationOperator _op;
  Inequation *_expr1;
  Inequation *_expr2;

public:
  CompositeInequation(InequationOperator op, Inequation *expr1, Inequation *expr2);
  virtual ~CompositeInequation();

  virtual bool calculate(Environment &env);
};

#endif
