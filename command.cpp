#include <iostream>
#include <string>
#include <cassert>

#include "flow.hpp"

#include "command.hpp"

using namespace std;


cairo_surface_t *cairo_surface = NULL;
cairo_t *cairo = NULL;

/**
 * Initialize the cairo context.
 * @param format The image format. See <http://cairographics.org/manual/cairo-Image-Surfaces.html#cairo-format-t>
 * @param width  The width of the canvas.
 * @param height The height of the canvas.
 */
void Command::init_cairo(cairo_format_t format, size_t width, size_t height) {
    cairo_surface = cairo_image_surface_create(format, width, height);
    cairo = cairo_create(cairo_surface);
    cairo_set_line_width(cairo, 1.0);
    cairo_set_source_rgb(cairo, 0, 0, 0);
}

/**
 * Free cairo context.
 */
void Command::close_cairo() {
    cairo_destroy(cairo);
    cairo_surface_destroy(cairo_surface);
}

/**
 * Write the cairo drawing in a PNG file.
 * @param filename The filename of the PNG file.
 */
void Command::write_png_file(const char *filename) {
    cairo_surface_write_to_png(cairo_surface, filename);
}

Command::Command(CommandName name, Path *p) {
    _name = name;
    _path = p;
}

Command::~Command() {
    delete _path;
}

Path* Command::get_path() {
    return _path;
}

void Command::print() {
    string s;

    switch(_name) {
        case DRAW:
            s += "draw ";
            break;

        case FILL:
            s += "fill ";
            break;
    }

    // s += _path.to_tmp_variable();

    cout << s << endl;
}

/**
 * Calls the command.
 */
void Command::execute(Environment &env) {
    assert(cairo && cairo_surface);

    // Initialization
    auto it = _path->begin();
    Point p = (*it)->calculate(env);
    cairo_move_to(cairo, p.get_x(), p.get_y()); // we move to the first point
    
    // Iteration
    for (++it; it != _path->end(); ++it) {
        p = (*it)->calculate(env);
        cairo_line_to(cairo, p.get_x(), p.get_y());
    }

    switch (_name) {
        case DRAW:
            cairo_stroke(cairo);
            break;

        case FILL:
            cairo_fill(cairo);
            break;
    }
}

VariableCommand::VariableCommand(CommandName name, const string &var) {
    _name = name;
    _var = var;
}

VariableCommand::~VariableCommand() {
    
}

/**
 * Calls the command.
 */
void VariableCommand::execute(Environment &env) {
    assert(cairo && cairo_surface);

    Variable var = env.get_variable(_var);

    switch(var.type) {
        case PATH_TYPE: {
            Path *p = (Path*) var.value;
            Command cmd = Command(_name, p);
            cmd.execute(env);
            break;
        }

        case IMAGE_TYPE: {
            Flow *f = (Flow*) var.value;
            Environment child_env(&env);
            f->execute(child_env);
            break;  
        }
    }
}