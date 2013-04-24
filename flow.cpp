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

void Flow::execute(const Environment &env) {
  // for (auto it = _instructions.begin(); it != _instructions.end(); it) {
  //   Command c = *((Command*) *it);
  //   cout << "commande " << c.get_path().to_string() << endl;
  // }

  for (auto it = _instructions.begin(); it != _instructions.end(); ++it) {
    (*it)->execute(env);
  }
}
