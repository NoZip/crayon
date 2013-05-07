#include "while.hpp"
#include "inequation.hpp"
#include "flow.hpp"


While::While(Inequation *comp, Flow *flow){ //initialiser inequation a true?
  _comp = comp;
  _flow = flow;
}

void While::execute(Environment &env){
   while(_comp->calculate()){
    _flow->execute(env);
   }
}
