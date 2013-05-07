#ifndef INSTRUCTION
#define INSTRUCTION

#include "environment.hpp"

class Instruction {
public:
  ~Instruction() {}

  virtual void execute(Environment &env) = 0;
};

#endif
