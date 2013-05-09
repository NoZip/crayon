#include <cassert>
#include "point_expression.hpp"

//Oh! mais...

//LES DESTRUCTEURS ONT TOUT CASSAY!

//TODO: reparer les erreurs de link causes par les destructeurs

using namespace std;

VarPointExpression::VarPointExpression(const string &name){
  _name = name;
}

//VarPointExpression::~VarPointExpression(){}

Point VarPointExpression::calculate(Environment &env){
  Variable var = env.get_variable(_name);
  assert(var.type == SCALAR);
  Point value = ((PointExpression *) var.value)->calculate(env);
  return value;
}

BinaryPointExpression::BinaryPointExpression(ExpressionOperator op, PointExpression *expr1, PointExpression *expr2) {
	_op = op;
	_expr1 = expr1;
	_expr2 = expr2;
}

/*BinaryPointExpression::~BinaryPointExpression() {
	delete _expr1;
	delete _expr2;
	}*/

Point BinaryPointExpression::calculate(Environment &env) {
  Point result(NULL,NULL);

  switch(_op) {
  case EXPR_PLUS:
    result = _expr1->calculate(env) + _expr2->calculate(env);
    break;
    /* 
  case EXPR_MINUS:
    result = _expr1->calculate(env) - _expr2->calculate(env);
    break;
    
  case EXPR_MUL:
    result = _expr1->calculate(env) * _expr2->calculate(env);
    break;
    
  case EXPR_DIV:
    result = _expr1->calculate(env) / _expr2->calculate(env);
    break;*/
  }
  
  return result;
}

ConstantPointExpression::ConstantPointExpression(const Point &value) {
  _value = value;
}

/*ConstantPointExpression::~ConstantPointExpression() {
	
  }*/

Point ConstantPointExpression::calculate(Environment &env) {
	return _value;
}
