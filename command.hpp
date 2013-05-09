#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <cstddef>
#include <string>

#include <cairo.h>

#include "path.hpp"
#include "instruction.hpp"

using std::string;


enum CommandName {
    DRAW,
    FILL
};

class Command : public Instruction {
protected:
    CommandName _name;
    Path *_path;

public:
    static void init_cairo(cairo_format_t format, size_t width, size_t height);
    static void close_cairo();

    static void write_png_file(const char *filename);

    Command(CommandName name, Path *p);
    virtual ~Command();

    Path* get_path();

    virtual void print();
    virtual void execute(Environment &env);
};

class VariableCommand : public Instruction {
protected:
    CommandName _name;
    string _var;

public:
    VariableCommand(CommandName name, const string &var);
    virtual ~VariableCommand();

    virtual void execute(Environment &env);
};

#endif
