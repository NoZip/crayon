#include <list>
#include "flow.hpp"

using namespace std;

void Flow::append(const Instruction &i){
  this->push_back(i);
}

void Flow::append_cycle(){
  this->push_back(front());
}
