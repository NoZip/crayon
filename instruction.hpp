#ifndef INSTRUCTION
#define INSTRUCTION

#include "environment.hpp"

class Instruction {
public:
  virtual void execute(const Environment &env) = 0;
};

#endif
