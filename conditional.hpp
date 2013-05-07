#ifndef CONDITIONAL
#define CONDITIONAL

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class Conditional : public Instruction {
protected :
  Inequation *_condition;
  Flow *_consequent;
  Flow *_alternative;

public :
  Conditional(Inequation *condition, Flow *consequent, Flow *alternative);
  virtual ~Conditional();
  void execute(Environment &env);

};


#endif
