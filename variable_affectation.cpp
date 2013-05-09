#include <iostream>
#include <cassert>

#include "variable_affectation.hpp"

using namespace std;

VariableInitialization::VariableInitialization(const string &name, VariableType type, void *value) {
    _name = name;
    _value = {type, value};
}

VariableInitialization::~VariableInitialization() {

}

void VariableInitialization::print() {
    std::cout << "variable " << _name << " initialized" << std::endl;
}

void VariableInitialization::execute(Environment &env) {
    env.set_variable(_name, _value.type, _value.value, true);
}

VariableAffectation::VariableAffectation(const string &name, VariableType type, void *value) {
    _name = name;
    _value = {type, value};
}

VariableAffectation::~VariableAffectation() {

}

void VariableAffectation::print() {
    std::cout << "variable " << _name << " set " << std::endl;
}

void VariableAffectation::execute(Environment &env) {
    env.set_variable(_name, _value.type, _value.value);
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
}