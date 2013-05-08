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
  PATH,
  IMAGE
};

struct Variable {
  VariableType type;
  void *value;
};

class Environment {
protected:
  Environment *_parent;
  map<string, Variable> _variables;

public:
  Environment();
  Environment(Environment *parent);
  virtual ~Environment();

  Environment* get_parent();
  
  Variable get_variable(const string &name);
  void set_variable(const string &name, VariableType type, void *value);
  void clear();
};

#endif