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


  void print();
  bool is_block();
  virtual void execute(Environment &env);

protected:
  list<Instruction*> _instructions;
};

#endif
