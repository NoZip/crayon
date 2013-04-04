#include <cassert>

#include "command.hpp"

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
}

/**
 * Free cairo context.
 */
void Command::close_cairo() {

}

Command::Command(CommandName name, Path p) {
    m_name = name;
    m_path = p;
}

/**
 * Calls the command.
 */
void Command::operator()() {
    assert(cairo && cairo_surface);

    // Initialization
    auto it = m_path.begin();
    cairo_move_to(cairo, it->get_x(), it->get_y()); // we move to the first point
    
    // Iteration
    for (++it; it != m_path.end(); ++it) {
        cairo_line_to(cairo, it->get_x(), it->get_y());
    }

    switch (m_name) {
        case DRAW:
            cairo_stroke(cairo);
            break;

        case FILL:
            cairo_fill(cairo);
            break;
    }
}