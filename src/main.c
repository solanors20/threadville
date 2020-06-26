#include <gtk/gtk.h>
#include <unistd.h>
#include <unistd.h>

#include "lib/threadville_globals.h"
#include "lib/map.h"
#include "lib/initialize.h"
#include "lib/bus_logic.h"



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
		//buttons
		GtkWidget *w_btn_create_random_car;
		GtkWidget *w_btn_create_random_ambulance;
		GtkWidget *w_btn_create_car;
		//combobox
		GtkWidget *w_combo_car;
		//entry
		GtkWidget *w_entry_car;

} AppWidgets;

static gint64 last_tick = 0;
static guint tick_cb = 0;
static guint size =32;

static GtkWidget *draw;

static gboolean on_tick (gpointer user_data);



int main(int argc, char **argv) 
{
	GtkBuilder *builder;
	GtkWidget *window;
	GError *error = NULL;

	AppWidgets *widgets = g_slice_new(AppWidgets);

	/* Init GTK+ */
	gtk_init(&argc, &argv);

	/* Init logic*/
	initialize();

	init_buses();

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

	// draw
	draw = GTK_WIDGET(gtk_builder_get_object(builder, "draw"));


  //checks
	widgets->w_check_red_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_red_bus"));
	widgets->w_check_green_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_green_bus"));
	widgets->w_check_blue_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_blue_bus"));
	widgets->w_check_white_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_white_bus"));
	widgets->w_check_gray_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_gray_bus"));
	widgets->w_check_black_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_black_bus"));
	widgets->w_check_pink_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_pink_bus"));
	widgets->w_check_light_blue_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_light_blue_bus"));
	widgets->w_check_orange_bus = GTK_WIDGET(gtk_builder_get_object(builder, "check_orange_bus"));
	//combo
	widgets->w_combo_car = GTK_WIDGET(gtk_builder_get_object(builder, "combo_car"));
	//entry
	widgets->w_entry_car = GTK_WIDGET(gtk_builder_get_object(builder, "entry_car"));


	// widgets pointer will be passed to all widget handler functions as the user_data parameter
  gtk_builder_connect_signals(builder, widgets);    // note: second parameter is not NULL


	/* Destroy builder, since we don't need it anymore */
	g_object_unref(G_OBJECT(builder));

	/* Show window. All other widgets are automatically shown by GtkBuilder */
	gtk_widget_show(window);

	tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size)); 

	/* Start main loop */
	gtk_main();

	g_slice_free(AppWidgets, widgets);

	return (0);
}

static gboolean on_tick (gpointer user_data) {
    gint64 current = g_get_real_time ();
    gboolean changed = FALSE;
    if ((current - last_tick) < (1000/ FPS)) {
        last_tick = current;
        return G_SOURCE_CONTINUE;
    }

    gtk_widget_queue_draw_area(draw, 0, 0, WIDTH, HEIGTH);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}

static void draw_car(cairo_t * cr, VEHICLE * vehicule) {   
    if(vehicule->run){
        if(vehicule->color==1)
            cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
        else if(vehicule->color==2)
            cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
        else if(vehicule->color==3)
            cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
        else if(vehicule->color==4)
            cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
        else if(vehicule->color==5)
            cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
        else if(vehicule->color==6)
            cairo_set_source_rgb (cr, 1.0, 1.0, 0.0);
        else if(vehicule->color==7)
            cairo_set_source_rgb (cr, 1.0, 0.5, 0.0);
        else if(vehicule->color==8)
            cairo_set_source_rgb (cr, 0.7, 0.7, 0.7);
        else if(vehicule->color==9)
            cairo_set_source_rgb (cr, 1.0, 0.4, 0.45);
        else if(vehicule->color==10)
            cairo_set_source_rgb (cr, 0.75, 0.9, 0.92);

        if(vehicule->type==1){
        	cairo_arc(cr, vehicule->x, vehicule->y+10, TILESIZE/2, 0, 2*3.14);
        	cairo_fill (cr);
	}else{
		cairo_rectangle(cr, vehicule->x-10, vehicule->y,TILESIZE+TILESIZE*fabs(vehicule->dx),TILESIZE+TILESIZE*fabs(vehicule->dy));
                cairo_fill (cr);
	}
        
        if(vehicule->color!=4)
            cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
        else
            cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	
        cairo_move_to(cr, vehicule->x-8, vehicule->y+12);
        cairo_set_font_size(cr, 12);
        cairo_show_text(cr, vehicule -> nextDestination);
        
    }
    
} // draw_car

void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	draw_background(cr);

	int i;
	for(i=0; i<threadCounter; i++){
			draw_car(cr, vehicules[i]);
	} // for 
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

void on_btn_create_random_car_clicked(GtkButton *button, AppWidgets *widgets)
{
	g_print("Random car clicked\n");
}

void on_btn_create_random_ambulance_clicked(GtkButton *button, AppWidgets *widgets)
{
	g_print("Random ambulance clicked\n");
}

void on_btn_create_car_clicked(GtkButton *button, AppWidgets *widgets)
{
	g_print("Create car clicked\n");
	const gchar *car_selected, *destinations;
	
	destinations = gtk_entry_get_text(GTK_ENTRY(widgets->w_entry_car));
	car_selected = gtk_combo_box_get_active_id(GTK_COMBO_BOX(widgets->w_combo_car));
	g_print("Car selected: %s\n", car_selected);
	g_print("Destinations: %s\n", destinations);
	
	//clean entry text
	gtk_entry_set_text(GTK_ENTRY(widgets->w_entry_car), "");
}