#include "for.hpp"

using namespace std;

For::For(Instruction *var1, Inequation *comp, Instruction *var2, Flow *flow){
  _var1 = var1;
  _comp = comp;
  _var2 = var2;
  _flow = flow;
}

For::~For() {
  delete _var1;
  delete _comp;
  delete _var2;
  delete _flow;
}

bool For::is_block() {
	return true;
}

void For::execute(Environment &env){
  _var1->execute(env);
  Environment child_env(&env);
  
  while(_comp->calculate(env)){
    _flow->execute(child_env);
    child_env.clear();
    _var2->execute(env);
  }
}
