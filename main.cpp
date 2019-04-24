#include <iostream>
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <math.h>
#include <time.h>
#include "C_radar_sweep.h"
#include "C_radar_ray.h"

#define DIM 620.0
#define RAD_KM 50.0
#define TEST_MODE True

using namespace std;

cairo_surface_t* cairo_create_x11_surface(int x, int y)
{
    Display *dsp;
    Drawable da;
    int screen;
    cairo_surface_t *sfc;

    if ((dsp = XOpenDisplay(NULL)) == NULL) exit(1);
    screen = DefaultScreen(dsp);
    da = XCreateSimpleWindow(dsp, DefaultRootWindow(dsp),
        0, 0, x, y, 0, 0, 0);
    XSelectInput(dsp, da, ButtonPressMask | KeyPressMask);
    XMapWindow(dsp, da);

    sfc = cairo_xlib_surface_create(dsp, da,
        DefaultVisual(dsp, screen), x, y);
    cairo_xlib_surface_set_size(sfc, x, y);

    return sfc;
}

int cairo_check_event(cairo_surface_t *sfc, int block)
{
    char keybuf[8];
    KeySym key;
    XEvent e;

    for (;;)
    {
        if (block || XPending(cairo_xlib_surface_get_display(sfc)))
            XNextEvent(cairo_xlib_surface_get_display(sfc), &e);
        else
            return 0;

        switch (e.type)
        {
            case ButtonPress:
                return -e.xbutton.button;
            case KeyPress:
                XLookupString(&e.xkey, keybuf, sizeof(keybuf), &key, NULL);
                return key;
            default:
                fprintf(stderr, "Dropping unhandled XEevent.type = %d.\n", e.type);
        }
    }
}

void cairo_close_x11_surface(cairo_surface_t *sfc)
{
   Display *dsp = cairo_xlib_surface_get_display(sfc);

   cairo_surface_destroy(sfc);
   XCloseDisplay(dsp);
}

int main(int argc, char* argv[])
{
    int signal = 1;
    struct timespec ts = {0, 50000000};

    cairo_surface_t *sfc;
    cairo_t *ctx;

    sfc = cairo_create_x11_surface(DIM, DIM);
    ctx = cairo_create(sfc);

    cairo_translate(ctx, DIM/2, DIM/2);

    cairo_set_source_rgb(ctx, 0.3, 0.3, 0.3); //выбор серого цвета
    cairo_paint(ctx); //залить цветом весь регион

    C_radar_sweep SW(DIM-20, RAD_KM);
    SW.draw(ctx);
    C_radar_ray R((DIM-20)/2, 0.05, 0.02);
    R.draw(ctx, 0);

    cairo_surface_flush(sfc);

    while(signal == 1)
    {
        cairo_push_group(ctx);
        cairo_set_source_rgb(ctx, 0.3, 0.3, 0.3); //выбор серого цвета
        cairo_paint(ctx);
        SW.draw(ctx);
        R.draw(ctx, -1);
        cairo_pop_group_to_source(ctx);
        cairo_paint(ctx);

        if(cairo_check_event(sfc, 0) == 0xff1b) signal = 0;
        nanosleep(&ts, NULL);
    }

    /*
    cairo_move_to(ctx, 0, 0);
    cairo_set_line_width(ctx, 4);
    cairo_set_source_rgb(ctx, 0, 0, 0.8);
    cairo_arc(ctx, 0, 0, 300, 0.5 * M_PI, 0.5 * M_PI + 0.05 * M_PI);
    cairo_fill(ctx);
    */




    //XFlush(cairo_xlib_surface_get_display(sfc));
    cairo_destroy(ctx);
    //cairo_check_event(sfc, 1);
    cairo_close_x11_surface(sfc);

    return 0;
}
