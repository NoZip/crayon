#include <cassert>

#include "expression.hpp"


Expression::~Expression() {
	
}


ConstantExpression::ConstantExpression(float value) {
	_value = value;
}

ConstantExpression::~ConstantExpression() {
	
}

float ConstantExpression::calculate() {
	return _value;
}


VariableExpression::VariableExpression(Environment *env, const string &name) {
	_env = env;
	_name = name;
}

VariableExpression::~VariableExpression() {
	
}

float VariableExpression::calculate() {
	Variable var = _env->get_variable(_name);
	assert(var.type == SCALAR);
	float value = ((Expression *) var.value)->calculate();
	return value;
}


UnaryExpression::UnaryExpression(ExpressionOperator op, Expression *expr) {
	_op = op;
	_expr = expr;
}

UnaryExpression::~UnaryExpression() {
	delete _expr;
}

float UnaryExpression::calculate() {
	float result;

	switch(_op) {
		case EXPR_NEGATE:
			result = -_expr->calculate();
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

float BinaryExpression::calculate() {
	float result;

	switch(_op) {
		case EXPR_PLUS:
			result = _expr1->calculate() + _expr2->calculate();
			break;

		case EXPR_MINUS:
			result = _expr1->calculate() - _expr2->calculate();
			break;

		case EXPR_MUL:
			result = _expr1->calculate() * _expr2->calculate();
			break;

		case EXPR_DIV:
			result = _expr1->calculate() / _expr2->calculate();
			break;
	}

	return result;
}