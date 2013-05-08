#ifndef INSTRUCTION
#define INSTRUCTION

#include <iostream>

#include "environment.hpp"

class Instruction {
public:
  ~Instruction() {}

  virtual void print() {std::cout << "instruction" << std::endl;}
  virtual void execute() = 0;
};

#endif
