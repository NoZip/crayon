#ifndef _ERROR_
#define _ERROR_

#include <exception>

#include <string>

using std::string;

//classe d'erreur pour récuperer et
//traiter les exceptions
class VariableError : public std::exception {
protected:
	string _message;

public:
	VariableError(const string &message) throw();
	virtual ~VariableError() throw();

	virtual const char * what() const throw();
};

#endif
