#include "C_radar_sweep.h"
#include <math.h>
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>

C_radar_sweep::C_radar_sweep(double dim)
{
    DIAMETER = dim;
};

void C_radar_sweep::draw(cairo_t* ctx)
{
    cairo_set_line_width(ctx, 4); //установить толщину линии
    cairo_set_source_rgb(ctx, RED, GREEN, BLUE); //выбор зеленого цвета для линий
    cairo_arc(ctx, 0, 0, DIAMETER/2, 0, 2 * M_PI); //круг в нулевых координатах от угла 0 до 2пи
    cairo_stroke_preserve(ctx); //нарисовать линию
    cairo_set_source_rgb(ctx, 0, 0, 0);
    cairo_fill(ctx); //залить круг

    cairo_set_line_width(ctx, 2);
    cairo_set_source_rgb(ctx, RED, GREEN, BLUE);
    cairo_arc(ctx, 0, 0, DIAMETER/4, 0, 2 * M_PI);
    cairo_stroke(ctx);
};
