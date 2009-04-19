#include <glib.h>
#include <gtk/gtk.h>

int
main( int argc, char *argv[] )
{
	gtk_init(&argc, &argv);
	GdkEvent event;
	event.client.type = GDK_CLIENT_EVENT;
	event.client.send_event = TRUE;
	event.client.window = NULL;
	event.client.message_type = gdk_atom_intern("_GTK_READ_RCFILES", FALSE);
	event.client.data_format = 8;
	gdk_event_send_clientmessage_toall(&event);
	return 0;
}
