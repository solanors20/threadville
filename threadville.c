/*
 * threadville.c
 *
 *  Created on: May 24, 2015
 *      Author: davidp
 *
 *  Compile me with:
 *  	gcc `pkg-config --cflags gtk+-3.0` -o threadville threadville.c `pkg-config --libs gtk+-3.0`
 */

#include <gtk-3.0/gtk/gtk.h>
#include <unistd.h>

int main(int argc, char **argv) {
	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;

	/* Init GTK+ */
	gtk_init(&argc, &argv);

	/* Create new GtkBuilder object */
	builder = gtk_builder_new_from_file("threadville.glade");
	/* Load UI from file. If error occurs, report it and quit application.
	 * Replace "tut.glade" with your saved project. */
	if (!builder) {
		g_warning("%s", error->message);
		g_free(error);
		return (1);
	}

	/* Get main window pointer from UI */
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

	/* Connect signals */
	gtk_builder_connect_signals(builder, NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	/* Destroy builder, since we don't need it anymore */
	g_object_unref(G_OBJECT(builder));

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show(window);

	/* Start main loop */
	gtk_main();

	return (0);
}
