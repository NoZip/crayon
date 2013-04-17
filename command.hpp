#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <cstddef>

#include <cairo.h>

#include "path.hpp"
#include "instruction.hpp"

enum CommandName {
    DRAW,
    FILL
};

class Command : public Instruction {
protected:
    CommandName m_name;
    Path m_path;

public:
    static void init_cairo(cairo_format_t format, size_t width, size_t height);
    static void close_cairo();

    static void write_png_file(const char *filename);

    Command(CommandName name, Path p);

    Path get_path();

    void execute();
};

#endif
