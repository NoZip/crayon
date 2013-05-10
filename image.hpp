#ifndef _IMAGE_
#define _IMAGE_

#include "environment.hpp"
#include "flow.hpp"

//Classe qui représente une image, c'est
//à dire l'ensemble des instructions et des variables
//qui la composent, donc son flow et son environnement
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
