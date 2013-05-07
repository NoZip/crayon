#ifndef CONDITIONAL
#define CONDITIONAL
#include "instruction.hpp"
#include "flow.hpp"

class Conditional : public Instruction {

protected:
  Inequation *condition;
  Flow *consequent;
  Flow *alternative;

public: 
  Conditional(Inequation *condition, Flow *consequent, Flow *alternative);
  virtual ~Conditional();
  void execute();

};


#endif
