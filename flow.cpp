#include <cassert>
#include <iostream>

#include "flow.hpp"

#include "command.hpp"

using namespace std;

Flow::Flow() {

}

Flow::~Flow() {
  for (auto it = _instructions.begin(); it != _instructions.end(); ++it) {
    delete *it;
  }
}

void Flow::append(Instruction *i) {
  assert(i);

  _instructions.push_back(i);
}

void Flow::print() {
  cout << "print flow" << endl;
  for (auto it = _instructions.begin(); it != _instructions.end(); ++it) {
    Instruction *ins = *it;
    ins->print();
  }
}

void Flow::execute() {
  for (auto it = _instructions.begin(); it != _instructions.end(); ++it) {
    (*it)->execute();
  }
}
