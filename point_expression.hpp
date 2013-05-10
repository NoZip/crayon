#ifndef _POINTEXPRESSION_
#define _POINTEXPRESSION_

#include "point.hpp"
#include "environment.hpp"
#include "utils.hpp"

//Classe qui permet de recuperer un point qui
//est sous forme d'expression
class PointExpression {
public:
  virtual ~PointExpression() {}
  virtual Point calculate(Environment &env) = 0;
};

//Classe qui permet d'extraire un point d'une variable
class VarPointExpression : public PointExpression{
protected:
  string _name;

public:
  VarPointExpression(const string &name);
  virtual ~VarPointExpression();
  virtual Point calculate(Environment &env);
  };

//classe qui permet de faire des operations binaires sur des points
//exemple: p1+p2 (une translation)
class BinaryPointExpression : public PointExpression {
protected:
  ExpressionOperator _op;
  PointExpression *_expr1;
  PointExpression *_expr2;

public:
  BinaryPointExpression(ExpressionOperator op, PointExpression *expr1, PointExpression *expr2);
  virtual ~BinaryPointExpression();

  virtual Point calculate(Environment &env);
};

//classe qui contient deux expressions, chacune
//representant les coordonnées du point
class ConstantPointExpression : public PointExpression {
protected:
  Expression *_x;
  Expression *_y;

public:
  ConstantPointExpression(Expression *x, Expression *y);
  virtual ~ConstantPointExpression();

  virtual Point calculate(Environment &env);
};

//pour effectuer une rotation
class RotatePointExpression : public PointExpression{
protected:
  PointExpression *_p1;
  PointExpression *_p2;
  Expression *_angle;

public:
  RotatePointExpression(PointExpression *p1, PointExpression *p2, Expression *_angle);
  Point calculate(Environment &env);
};

#endif
