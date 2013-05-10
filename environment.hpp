#ifndef ENVIRONMENT
#define ENVIRONMENT

#include <string>
#include <map>

using std::string;
using std::map;

enum VariableType {
  SCALAR,
  BOOLEAN,
  VECTOR2D,
  PATH_TYPE,
  IMAGE_TYPE
};

struct Variable {
  VariableType type;
  void *value;
};

//Contient les variables du contexte actuel
//et l'environment parent pour pouvoir remonter
class Environment {
protected:
  Environment *_parent;
  map<string, Variable> _variables;

public:
  Environment();
  Environment(Environment *parent);
  virtual ~Environment();

  Environment* get_parent();

  int deep(); //profondeur de l'arbre (pour debug)
  
  Variable get_variable(const string &name);
  void set_variable(const string &name, VariableType type, void *value, bool initialization=false);
  void clear();
};

#endif
