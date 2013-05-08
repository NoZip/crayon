#ifndef INSTRUCTION
#define INSTRUCTION

#include <iostream>

#include "environment.hpp"

class Instruction {
public:
  ~Instruction() {}

  virtual void print() {std::cout << "instruction" << std::endl;}
  virtual bool is_block() {return false;}
  virtual void execute(Environment &env) = 0;
};

#endif
