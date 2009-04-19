/* LDFLAGS='-L/usr/X11R6/lib/ -lX11 -lXext -lXss' make xidle */
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/scrnsaver.h>

int
main(int argc, char *argv[])
{
	XScreenSaverInfo info;
	Display *dpy = XOpenDisplay(NULL);

	if(NULL == dpy) {
		fprintf(stderr, "failed to open display\n");
		return 1;
	}

	XScreenSaverQueryInfo(dpy, RootWindow(dpy, DefaultScreen(dpy)), &info);
	printf("%ld\n", info.idle / 1000);
	return 0;
}
