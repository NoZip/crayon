#include <iostream>
#include <cassert>

#include "variable_affectation.hpp"

using namespace std;

VariableAffectation::VariableAffectation(const string &name, VariableType type, Expression *value) {
    _name = name;
    _value = {type, value};
}

VariableAffectation::~VariableAffectation() {

}

void VariableAffectation::print() {
    std::cout << "variable " << _name << " set" << std::endl;
}

void VariableAffectation::execute(Environment &env) {
    env.set_variable(_name, _value.type, _value.value);
    print();
}

VariableIncrement::VariableIncrement(const string &name, ExpressionOperator op, Expression *value) {
	_name = name;
	_op = _op;
	_expr = value;
}

VariableIncrement::~VariableIncrement() {

}

void VariableIncrement::print() {
	std::cout << "variable " << _name << " modified" << std::endl;
}

void VariableIncrement::execute(Environment &env) {
	Variable var = env.get_variable(_name);
	assert(var.type == SCALAR);
	Expression *expr = (Expression*) var.value;
	env.set_variable(_name, SCALAR, new BinaryExpression(_op, expr, _expr));
	print();
}