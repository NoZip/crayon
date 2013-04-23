#ifndef FLOW
#define FLOW

#include <list>

#include "instruction.hpp"

using std::list;

class Flow : public list<Instruction*>, public Instruction {
public:
  virtual ~Flow();

  void append(Instruction *i);
  void execute();
};

#endif
