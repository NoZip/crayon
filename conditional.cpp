#include "instruction.hpp"
#include "inequation.hpp"

Conditional::Conditional(Inequation *condition, Flow *consequent, Flow *alternative = NULL){
  _condition = condition;
  _consequent = consequent;
  _alternative = alternative;
}

// Conditional::Conditional(Inequation *condition, Flow* consequent){
//   _condition = condition;
//   _consequent = consequent;
//   _alternative = NULL;
// }

Conditional::~Conditional(){

}

void Conditional::execute() {
  if(_condition->calculate()){
    _consequent->execute();

  }else{
    if(_alternative)
      _alternative->execute();
  }
}
  
  
