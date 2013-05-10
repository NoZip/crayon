#ifndef _FOR_
#define _FOR_

#include "instruction.hpp"
#include "inequation.hpp"
#include "flow.hpp"

//Classe qui caractrise l'instruction for
class For: public Instruction {
protected:
  //var1 represente la premiere affectation pour le 1er tour
  //var2 represente la variable inc/decrementée à chaque tour
  //inequation représente la condition de la boucle
  //flow contient le code éxécuté à chaque tour
  Instruction *_var1, *_var2;
  Inequation *_comp;
  Flow *_flow;
public:
  For(Instruction *var1, Inequation *comp, Instruction *var2, Flow *flow);
  ~For();

  //is_block() permet de savoir si on 
  //créé un nouvel environnement ou pas
  bool is_block();
  void execute(Environment &env);
};

#endif
