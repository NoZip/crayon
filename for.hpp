#ifndef _FOR_
#define _FOR_

#include "instruction.hpp"
#include "variable_affectation.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class For: public Instruction{
protected:
  VariableAffectation *_var1, *_var2;
  Inequation *_comp;
  Flow *_flow;
public:
  For(VariableAffectation *var1, Inequation *comp, VariableAffectation *var2, Flow *flow);
  void execute(Environment &env);
};

#endif
