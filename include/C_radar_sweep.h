#ifndef C_RADAR_SWEEP_H
#define C_RADAR_SWEEP_H
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>


class C_radar_sweep
{
    public:
        /** Default constructor */
        C_radar_sweep(double dim);
        void draw(cairo_t* ctx);

    protected:

    private:
        double DIAMETER;
        double RED = 0;
        double GREEN = 0.8;
        double BLUE = 0;
        /* TODO: Apply struct here
        struct DEFAULT_COLOR {
            double red = 0;
            double green = 0.8;
            double blue = 0;
        };
        */

};

#endif // C_RADAR_SWEEP_H
