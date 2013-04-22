#include "flow.hpp"


void Flow::append(Instruction *i) {
  this->push_back(i);
}

void Flow::execute() {
  for (auto it = this->begin(); it != this->end(); ++it) {
    (*it)->execute();
  }
}
