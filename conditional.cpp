#include "conditional.hpp"

Conditional::Conditional(Inequation *condition, Flow *consequent, Flow *alternative = NULL){
  _condition = condition;
  _consequent = consequent;
  _alternative = alternative;
}

Conditional::~Conditional(){

}

void Conditional::execute(Environment &env) {
  if(_condition->calculate()){
    _consequent->execute(env);

  }else{
    if(_alternative)
      _alternative->execute(env);
  }
}
  
  
