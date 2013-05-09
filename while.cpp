#include "while.hpp"


While::While(Inequation *comp, Flow *flow) { //initialiser inequation a true?
  _comp = comp;
  _flow = flow;
}

While::~While() {
	delete _comp;
	delete _flow;
}

bool While::is_block() {
  return true;
}

void While::execute(Environment &env){
  while(_comp->calculate(env)){
    _flow->execute(env);
  }
}