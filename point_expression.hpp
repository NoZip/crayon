#ifndef _POINTEXPRESSION_
#define _POINTEXPRESSION_

#include "point.hpp"
#include "environment.hpp"
#include "utils.hpp"

//Oh! mais...

//LES DESTRUCTEURS ONT TOUT CASSAY!!

//TODO: reparer les erreurs de link causes par les destructeurs

class PointExpression {
public:
  //virtual ~PointExpression();
  virtual Point calculate(Environment &env) = 0;
};

class VarPointExpression : public PointExpression{
protected:
  string _name;

public:
  VarPointExpression(const string &name);
  //virtual ~VarPointExpression();
  virtual Point calculate(Environment &env);
  };

class BinaryPointExpression : public PointExpression {
protected:
  ExpressionOperator _op;
  PointExpression *_expr1;
  PointExpression *_expr2;

public:
  BinaryPointExpression(ExpressionOperator op, PointExpression *expr1, PointExpression *expr2);
  //virtual ~BinaryPointExpression();

  virtual Point calculate(Environment &env);
};

class ConstantPointExpression : public PointExpression {
protected:
  Point _value;

public:
  ConstantPointExpression(const Point &value);
  //virtual ~ConstantPointExpression();

  virtual Point calculate(Environment &env);
};

#endif
