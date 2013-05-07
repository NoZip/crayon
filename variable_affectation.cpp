#include <iostream>

#include "variable_affectation.hpp"

using namespace std;

VariableAffectation::VariableAffectation(const string &name, VariableType type, Expression *value) {
    _name = name;
    _value = {type, value};
}

VariableAffectation::~VariableAffectation() {

}

void VariableAffectation::print() {
    std::cout << "variable " << std::endl;
}

void VariableAffectation::execute(Environment &env) {
    env.set_variable(_name, _value.type, _value.value);
}