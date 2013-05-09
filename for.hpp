#ifndef _FOR_
#define _FOR_

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class For: public Instruction {
protected:
  Instruction *_var1, *_var2;
  Inequation *_comp;
  Flow *_flow;
public:
  For(Instruction *var1, Inequation *comp, Instruction *var2, Flow *flow);
  ~For();

  bool is_block();
  void execute(Environment &env);
};

#endif
