#ifndef FLOW
#define FLOW

#include <list>

#include "instruction.hpp"

using std::list;

class Flow : public Instruction {
public:
  Flow();
  virtual ~Flow();

  void append(Instruction *i);
  void execute(const Environment &env);

protected:
  list<Instruction*> _instructions;
};

#endif
