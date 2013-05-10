#ifndef EXPRESSION
#define EXPRESSION

#include <string>

#include "environment.hpp"
#include "utils.hpp"

using std::string;

//Une expression represente un noeud de
//l'arbre syntaxique des operations
//mathematiques. Calculer l'expression
//permet de récuperer sa valeur
class Expression {
public:
  virtual ~Expression();

  virtual float calculate(Environment &env) = 0;
};

//Une valeur constante d'une expression
class ConstantExpression : public Expression {
protected:
  float _value;

public:
  ConstantExpression(float value);
  virtual ~ConstantExpression();

  virtual float calculate(Environment &env);
};

//Classe qui permet de calculer une variable
//contenant une expression (et donc de l'extraire
//directement)
class VariableExpression : public Expression {
protected:
  string _name;
public:
  VariableExpression(const string &name);
  virtual ~VariableExpression();

  virtual float calculate(Environment &env);
};

//Une operation sur un element (ex: -3)
class UnaryExpression : public Expression {
protected:
  ExpressionOperator _op;
  Expression *_expr;

public:
  UnaryExpression(ExpressionOperator op, Expression *expr);
  virtual ~UnaryExpression();

  virtual float calculate(Environment &env);
};

//Une operation sur deux elements (ex: 1+1)
class BinaryExpression : public Expression {
protected:
  ExpressionOperator _op;
  Expression *_expr1;
  Expression *_expr2;

public:
  BinaryExpression(ExpressionOperator op, Expression *expr1, Expression *expr2);
  virtual ~BinaryExpression();

  virtual float calculate(Environment &env);
};

#endif
