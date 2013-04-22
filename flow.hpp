#include <list>

#include "instruction.hpp"

using namespace std;

class Flow : public list<Instruction*>, public Instruction {
public:
  void append(Instruction *i);
  
  void execute();
};