#include "conditional.hpp"

Conditional::Conditional(Inequation *condition, Flow *consequent, Flow *alternative){
  _condition = condition;
  _consequent = consequent;
  _alternative = alternative;
}

Conditional::~Conditional(){
	delete _condition;
	delete _consequent;
	delete _alternative;
}

bool Conditional::is_block() {
	return true;
}

void Conditional::execute(Environment &env) {
  if(_condition->calculate(env)){
    _consequent->execute(env);

  }
  else if(_alternative) {
    _alternative->execute(env);
  }
}
  
  
