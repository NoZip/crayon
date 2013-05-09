#include <cassert>
#include <cmath>

#include "expression.hpp"


Expression::~Expression() {
	
}


ConstantExpression::ConstantExpression(float value) {
	_value = value;
}

ConstantExpression::~ConstantExpression() {
	
}

float ConstantExpression::calculate(Environment &env) {
	return _value;
}


VariableExpression::VariableExpression(const string &name) {
	_name = name;
}

VariableExpression::~VariableExpression() {
	
}

float VariableExpression::calculate(Environment &env) {
	Variable var = env.get_variable(_name);
	assert(var.type == SCALAR);
	float value = ((Expression *) var.value)->calculate(env);
	return value;
}


UnaryExpression::UnaryExpression(ExpressionOperator op, Expression *expr) {
	_op = op;
	_expr = expr;
}

UnaryExpression::~UnaryExpression() {
	delete _expr;
}

float UnaryExpression::calculate(Environment &env) {
	float result;

	switch(_op) {
		case EXPR_NEGATE:
			result = -_expr->calculate(env);
			break;

		case EXPR_SIN:
			result = sin(_expr->calculate(env));
			break;

		case EXPR_COS:
			result = cos(_expr->calculate(env));
			break;
	}

	return result;
}


BinaryExpression::BinaryExpression(ExpressionOperator op, Expression *expr1, Expression *expr2) {
	_op = op;
	_expr1 = expr1;
	_expr2 = expr2;
}

BinaryExpression::~BinaryExpression() {
	delete _expr1;
	delete _expr2;
}

float BinaryExpression::calculate(Environment &env) {
	float result;

	switch(_op) {
		case EXPR_PLUS:
			result = _expr1->calculate(env) + _expr2->calculate(env);
			break;

		case EXPR_MINUS:
			result = _expr1->calculate(env) - _expr2->calculate(env);
			break;

		case EXPR_MUL:
			result = _expr1->calculate(env) * _expr2->calculate(env);
			break;

		case EXPR_DIV:
			result = _expr1->calculate(env) / _expr2->calculate(env);
			break;
	}

	return result;
}