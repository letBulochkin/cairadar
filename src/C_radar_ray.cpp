#include "C_radar_ray.h"
#include <math.h>

C_radar_ray::C_radar_ray(double rad, double angle, double speed)
{
    RADIUS = rad;
    REL_ANGLE = angle;
    INC_SPEED = speed;
}

void C_radar_ray::draw(cairo_t* ctx, double rel_angle_start)
{
    static double angle = 0;
    if (rel_angle_start != -1) angle = rel_angle_start * M_PI;

    cairo_move_to(ctx, 0, 0);
    cairo_set_line_width(ctx, 4);
    cairo_set_source_rgb(ctx, DEFAULT_COLOR.red, DEFAULT_COLOR.green, DEFAULT_COLOR.blue);
    cairo_arc(ctx, 0, 0, RADIUS, angle, angle + REL_ANGLE * M_PI);
    cairo_fill(ctx);

    angle = angle + INC_SPEED * M_PI;
}
