#ifndef _IMAGE_
#define _IMAGE_

#include "environment.hpp"
#include "flow.hpp"

class Image{
protected:
  Flow *_flow;
  Environment *_env;

public:
  Image(Flow *flow, Environment *env);
  void draw();
};

#endif

//todo: tester
