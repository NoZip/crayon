#ifndef EXPRESSION
#define EXPRESSION

#include <string>

#include "environment.hpp"

using std::string;

enum ExpressionOperator {
  EXPR_PLUS,
  EXPR_MINUS,
  EXPR_MUL,
  EXPR_DIV,
  EXPR_NEGATE
};

class Expression {
public:
  virtual ~Expression();

  virtual float calculate() = 0;
};

class ConstantExpression : public Expression {
protected:
  float _value;

public:
  ConstantExpression(float value);
  virtual ~ConstantExpression();

  virtual float calculate();
};

class VariableExpression : public Expression {
protected:
  Environment *_env;
  string _name;

public:
  VariableExpression(Environment *env, const string &name);
  virtual ~VariableExpression();

  virtual float calculate();
};

class UnaryExpression : public Expression {
protected:
  ExpressionOperator _op;
  Expression *_expr;

public:
  UnaryExpression(ExpressionOperator op, Expression *expr);
  virtual ~UnaryExpression();

  virtual float calculate();
};

class BinaryExpression : public Expression {
protected:
  ExpressionOperator _op;
  Expression *_expr1;
  Expression *_expr2;

public:
  BinaryExpression(ExpressionOperator op, Expression *expr1, Expression *expr2);
  virtual ~BinaryExpression();

  virtual float calculate();
};

#endif