#ifndef C_RADAR_SWEEP_H
#define C_RADAR_SWEEP_H
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include "radar_color_struct.h"


class C_radar_sweep
{
    public:
        /** Default constructor */
        C_radar_sweep(double dim);
        void draw(cairo_t* ctx);

    protected:

    private:
        double DIAMETER;
        color_triade DEFAULT_COLOR = { 0, 0.8, 0};
};

#endif // C_RADAR_SWEEP_H
