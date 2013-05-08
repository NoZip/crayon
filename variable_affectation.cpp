#include <iostream>

#include "variable_affectation.hpp"

using namespace std;

VariableAffectation::VariableAffectation(Environment *env, const string &name, VariableType type, Expression *value) {
    _env = env;
    _name = name;
    _value = {type, value};
}

VariableAffectation::~VariableAffectation() {

}

void VariableAffectation::print() {
    std::cout << "variable " << std::endl;
}

void VariableAffectation::execute() {
    _env->set_variable(_name, _value.type, _value.value);
}