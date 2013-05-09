#ifndef _WHILE_
#define _WHILE_

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class While: public Instruction{
protected:
  Inequation *_comp;
  Flow *_flow;

public:
  While(Inequation *comp, Flow *flow);
  ~While();

  bool is_block();
  void execute(Environment &env);
};

#endif
