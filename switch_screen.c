/*
 * I use this simple command to move the mouse to the other screen.
 * It is a very simple, silly and not portable at all.
 *
 * Author : Caio Filippo Corro
 */

#include <stdlib.h>
#include <X11/Xlib.h>

#define SCREEN_WIDTH 1280

int main() {
    Window w, c;
    int x, y, wx, wy;
    unsigned int m;

    Display *display = XOpenDisplay(NULL);
    if(display == NULL)
        return EXIT_FAILURE;

    Window root = DefaultRootWindow(display);
    XQueryPointer(display, root, &w, &c, &x, &y, &wx, &wy, &m);

    XWarpPointer(display, None, root, 0, 0, 0, 0, (x + SCREEN_WIDTH) % (SCREEN_WIDTH * 2), y);

    XFlush(display);
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
