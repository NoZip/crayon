#ifndef INSTRUCTION
#define INSTRUCTION

#include <iostream>

#include "environment.hpp"

//classe qui caracterise un instruction
//permet d'executer execute sur n'importe quel type d'instruction
class Instruction {
public:
  virtual ~Instruction() {}

  virtual void print() {std::cout << "instruction" << std::endl;}
  virtual bool is_block() {return false;}
  virtual void execute(Environment &env) = 0;
};

#endif
