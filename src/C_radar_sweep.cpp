#include "C_radar_sweep.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>

C_radar_sweep::C_radar_sweep(double dim, int km)
{
    DIAMETER = dim;
    KM = km;
    sprintf(OUTER_CAP, "%d", km);
    sprintf(INNER_CAP, "%d", km/2);
};

void C_radar_sweep::draw(cairo_t* ctx)
{
    cairo_set_line_width(ctx, 4); //установить толщину линии
    cairo_set_source_rgb(ctx, DEFAULT_COLOR.red, DEFAULT_COLOR.green, DEFAULT_COLOR.blue); //выбор зеленого цвета для линий
    cairo_arc(ctx, 0, 0, DIAMETER/2, 0, 2 * M_PI); //круг в нулевых координатах от угла 0 до 2пи
    cairo_stroke_preserve(ctx); //нарисовать линию
    cairo_set_source_rgb(ctx, 0, 0, 0);
    cairo_fill(ctx); //залить круг

    cairo_set_line_width(ctx, 2);
    cairo_set_source_rgb(ctx, DEFAULT_COLOR.red, DEFAULT_COLOR.green, DEFAULT_COLOR.blue);
    cairo_arc(ctx, 0, 0, DIAMETER/4, 0, 2 * M_PI);
    cairo_stroke(ctx);

    cairo_select_font_face(ctx, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(ctx, FONT_SIZE);
    cairo_set_source_rgb(ctx, DEFAULT_COLOR.red, DEFAULT_COLOR.green, DEFAULT_COLOR.blue);
    cairo_move_to(ctx,-(DIAMETER/2)+5, 0);
    cairo_show_text(ctx, OUTER_CAP);
    cairo_move_to(ctx,-(DIAMETER/4)+5, 0);
    cairo_show_text(ctx, INNER_CAP);
};
