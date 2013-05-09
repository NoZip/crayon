#ifndef _CONDITIONAL_
#define _CONDITIONAL_

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

class Conditional : public Instruction {
protected:
  Inequation *_condition;
  Flow *_consequent;
  Flow *_alternative;

public: 
  Conditional(Inequation *condition, Flow *consequent, Flow *alternative);
  virtual ~Conditional();

  bool is_block();
  void execute(Environment &env);

};


#endif
