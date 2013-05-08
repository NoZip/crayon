#include <iostream>

#include "error.hpp"

using namespace std;


VariableError::VariableError(const string &message) throw() {
	_message = message;
}

VariableError::~VariableError() throw() {

}

const char * VariableError::what() const throw() {
	return _message.c_str();
}