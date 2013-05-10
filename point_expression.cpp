#include <cassert>
#include "point_expression.hpp"

using namespace std;

VarPointExpression::VarPointExpression(const string &name){
  _name = name;
}

VarPointExpression::~VarPointExpression(){}

Point VarPointExpression::calculate(Environment &env){
  Variable var = env.get_variable(_name);
  assert(var.type == VECTOR2D);
  Point value = ((PointExpression *) var.value)->calculate(env);
  return value;
}

BinaryPointExpression::BinaryPointExpression(ExpressionOperator op, PointExpression *expr1, PointExpression *expr2) {
  _op = op;
  _expr1 = expr1;
  _expr2 = expr2;
}

BinaryPointExpression::~BinaryPointExpression() {
  delete _expr1;
  delete _expr2;
}

Point BinaryPointExpression::calculate(Environment &env) {
  
  switch(_op) {
  case EXPR_PLUS:
    return  _expr1->calculate(env) + _expr2->calculate(env);
    break;
    
  case EXPR_MINUS:
    return _expr1->calculate(env) - _expr2->calculate(env);
    break;
    
  case EXPR_MUL:
    return _expr1->calculate(env) * _expr2->calculate(env);
    break;
    
  case EXPR_DIV:
    return _expr1->calculate(env) / _expr2->calculate(env);
    break;
  }
    
}

ConstantPointExpression::ConstantPointExpression(Expression *x, Expression*y) {
  _x = x;
  _y = y;
}

ConstantPointExpression::~ConstantPointExpression() {
	
}

Point ConstantPointExpression::calculate(Environment &env) {
  return Point(_x->calculate(env), _y->calculate(env));
}

RotatePointExpression::RotatePointExpression(PointExpression *p1, PointExpression *p2, Expression *angle){
  _p1 = p1;
  _p2 = p2;
  _angle = angle;
}

Point RotatePointExpression::calculate(Environment &env){
  return (_p1->calculate(env)).rotate(_p2->calculate(env), _angle->calculate(env));
}
