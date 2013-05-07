#include <cassert>

#include "inequation.hpp"


Inequation::~Inequation() {
	
}


ConstantInequation::ConstantInequation(bool value) {
	_value = value;
}

ConstantInequation::~ConstantInequation() {
	
}

bool ConstantInequation::calculate() {
	return _value;
}


VariableInequation::VariableInequation(Environment *env, const string &name) {
	_env = env;
	_name = name;
}

VariableInequation::~VariableInequation() {
	
}

bool VariableInequation::calculate() {
	Variable var = _env->get_variable(_name);
	assert(var.type == SCALAR);
	bool value = *((bool *) var.value);
	return value;
}


UnaryInequation::UnaryInequation(InequationOperator op, Inequation *expr) {
	_op = op;
	_expr = expr;
}

UnaryInequation::~UnaryInequation() {
	delete _expr;
}

bool UnaryInequation::calculate() {
	bool result;

	switch(_op) {
		case INEQ_NOT:
			result = !_expr->calculate();
			break;
	}

	return result;
}


BinaryInequation::BinaryInequation(InequationOperator op, Expression *expr1, Expression *expr2) {
	_op = op;
	_expr1 = expr1;
	_expr2 = expr2;
}

BinaryInequation::~BinaryInequation() {
	delete _expr1;
	delete _expr2;
}

bool BinaryInequation::calculate() {
	bool result;

	switch(_op) {
		case INEQ_EQUAL:
			result = _expr1->calculate() == _expr2->calculate();
			break;

		case INEQ_NEQUAL:
			result = _expr1->calculate() != _expr2->calculate();
			break;

		case INEQ_GT:
			result = _expr1->calculate() > _expr2->calculate();
			break;

		case INEQ_GTE:
			result = _expr1->calculate() >= _expr2->calculate();
			break;

		case INEQ_LT:
			result = _expr1->calculate() < _expr2->calculate();
			break;

		case INEQ_LTE:
			result = _expr1->calculate() <= _expr2->calculate();
			break;
	}

	return result;
}


CompositeInequation::CompositeInequation(InequationOperator op, Inequation *expr1, Inequation *expr2) {
	_op = op;
	_expr1 = expr1;
	_expr2 = expr2;
}

CompositeInequation::~CompositeInequation() {
 delete _expr1;
 delete _expr2;
}

bool CompositeInequation::calculate() {
	bool result;

	switch(_op) {
		case INEQ_AND:
			result = _expr1->calculate() && _expr2->calculate();
			break;

		case INEQ_OR:
			result = _expr1->calculate() || _expr2->calculate();
			break;

	}

	return result;
}