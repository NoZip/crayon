#ifndef WHILE
#define WHILE

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class While: public Instruction{
protected:
  Inequation *_comp;
  Flow *_flow;

public:
  While(Inequation *comp, Flow *flow);
  void execute(Environment &env);
};

#endif
