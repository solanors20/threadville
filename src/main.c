#include <gtk/gtk.h>
#include <unistd.h>
#include <unistd.h>

#include "lib/threadville_globals.h"
#include "lib/map.h"

typedef struct {
	  //checks
    GtkWidget *w_check_red_bus;
    GtkWidget *w_check_green_bus;
    GtkWidget *w_check_blue_bus;
    GtkWidget *w_check_white_bus;
    GtkWidget *w_check_gray_bus;
    GtkWidget *w_check_black_bus;
    GtkWidget *w_check_pink_bus;
    GtkWidget *w_check_light_blue_bus;
    GtkWidget *w_check_orange_bus;
} AppWidgets;

int main(int argc, char **argv) {
	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;

	AppWidgets *widgets = g_slice_new(AppWidgets);

	/* Init GTK+ */
	gtk_init(&argc, &argv);

	/* Create new GtkBuilder object */
	builder = gtk_builder_new_from_file("glade/threadville.glade");
	/* Load UI from file. If error occurs, report it and quit application.
	 * Replace "tut.glade" with your saved project. */
	if (!builder) {
		g_warning("%s", error->message);
		g_free(error);
		return (1);
	}

	/* Get main window pointer from UI */
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));


	/* Connect signals */
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


  //buses
	widgets->w_check_red_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_red_bus"));
	widgets->w_check_green_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_green_bus"));
	widgets->w_check_blue_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_blue_bus"));
	widgets->w_check_white_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_white_bus"));
	widgets->w_check_gray_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_gray_bus"));
	widgets->w_check_black_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_black_bus"));
	widgets->w_check_pink_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_pink_bus"));
	widgets->w_check_light_blue_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_light_blue_bus"));
	widgets->w_check_orange_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_orange_bus"));


	// widgets pointer will be passed to all widget handler functions as the user_data parameter
  gtk_builder_connect_signals(builder, widgets);    // note: second parameter is not NULL


	/* Destroy builder, since we don't need it anymore */
	g_object_unref(G_OBJECT(builder));

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show(window);

	/* Start main loop */
	gtk_main();

	g_slice_free(AppWidgets, widgets);

	return (0);
}

void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	draw_background(cr);
}

void on_btn_select_all_buses_clicked(GtkButton *button, AppWidgets *widgets)
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_red_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_green_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_blue_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_white_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_gray_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_black_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_pink_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_light_blue_bus), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_orange_bus), TRUE);	
}

void on_btn_select_none_buses_clicked(GtkButton *button, AppWidgets *widgets)
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_red_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_green_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_blue_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_white_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_gray_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_black_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_pink_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_light_blue_bus), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widgets->w_check_orange_bus), FALSE);	
}

void on_check_red_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("red_bus is Checked\n");
		}
		else {
			g_print("red_bus is Unchecked\n");
		}
}

void on_check_green_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("green_bus is Checked\n");
		}
		else {
			g_print("green_bus is Unchecked\n");
		}
}

void on_check_blue_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("blue_bus is Checked\n");
		}
		else {
			g_print("blue_bus is Unchecked\n");
		}
}

void on_check_white_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("white_bus is Checked\n");
		}
		else {
			g_print("white_bus is Unchecked\n");
		}
}

void on_check_gray_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("gray_bus is Checked\n");
		}
		else {
			g_print("gray_bus is Unchecked\n");
		}
}

void on_check_black_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("black_bus is Checked\n");
		}
		else {
			g_print("black_bus is Unchecked\n");
		}
}

void on_check_pink_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("pink_bus is Checked\n");
		}
		else {
			g_print("pink_bus is Unchecked\n");
		}
}

void on_check_light_blue_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("light_blue_bus is Checked\n");
		}
		else {
			g_print("light_blue_bus is Unchecked\n");
		}
}

void on_check_orange_bus_toggled(GtkToggleButton *togglebutton, AppWidgets *widgets)
{
	if (gtk_toggle_button_get_active(togglebutton)) {
			g_print("orange_bus is Checked\n");
		}
		else {
			g_print("orange_bus is Unchecked\n");
		}
}



