#ifndef C_RADAR_RAY_H
#define C_RADAR_RAY_H
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include "radar_color_struct.h"

class C_radar_ray
{
    public:
        /** Default constructor */
        C_radar_ray(double rad, double angle, double speed);
        void draw(cairo_t* ctx, double rel_angle_start);

    protected:

    private:
        double RADIUS;
        double REL_ANGLE;
        double INC_SPEED;
        color_triade DEFAULT_COLOR = {0, 0, 0.8};
};

#endif // C_RADAR_RAY_H
