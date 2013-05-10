#ifndef _CONDITIONAL_
#define _CONDITIONAL_

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

//classe caracterisant les instructions
//conditionnelles (ex: if else)
class Conditional : public Instruction {
protected:
  Inequation *_condition; //la condition
  Flow *_consequent; //le bloc if
  Flow *_alternative; //le bloc else

public: 
  Conditional(Inequation *condition, Flow *consequent, Flow *alternative=nullptr);
  virtual ~Conditional();

  bool is_block();
  void execute(Environment &env);

};


#endif
