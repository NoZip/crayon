#include "for.hpp"
#include "variable_affectation.hpp"
#include "inequation.hpp"
#include "flow.hpp"

using namespace std;

For::For(VariableAffectation *var1, Inequation *comp, VariableAffectation *var2, Flow *flow){
  _var1 = var1;
  _comp = comp;
  _var2 = var2;
  _flow = flow;
}

void For::execute(Environment &env){
  _var1->execute(env);
  
  while(_comp->calculate()){
    _flow->execute(env);
    _var2->execute(env);
  }
}
