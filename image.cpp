#include "image.hpp"
#include "environment.hpp"
#include "flow.hpp"

Image::Image(Flow *flow, Environment *env){
  _flow = flow;
  _env = env;
}

void Image::draw(){ _flow->execute(*_env); }

//todo: tester
