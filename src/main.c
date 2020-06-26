
#include <string.h>
#include <limits.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "lib/threadville_globals.h"
#include "lib/map.h"
#include "lib/threadville_globals.h"



GtkWidget *window;
GtkWidget *button;
GtkWidget *buttonContar;
GtkWidget *button2;

//Buses
GtkWidget *labelBuses;

GtkWidget *buttonBusNaranja;
GtkWidget *buttonBusNaranjaOff;

GtkWidget *buttonBusRojo;
GtkWidget *buttonBusRojoOff;

GtkWidget *buttonBusVerde;
GtkWidget *buttonBusVerdeOff;

GtkWidget *buttonBusAzul;
GtkWidget *buttonBusAzulOff;

GtkWidget *buttonBusBlanco;
GtkWidget *buttonBusBlancoOff;

GtkWidget *buttonBusNegro;
GtkWidget *buttonBusNegroOff;

GtkWidget *buttonBusGris;
GtkWidget *buttonBusGrisOff;

GtkWidget *buttonBusRosa;
GtkWidget *buttonBusRosaOff;

GtkWidget *buttonBusCeleste;
GtkWidget *buttonBusCelesteOff;

GtkWidget *button_box;
GtkWidget *fixed;   

//Carros
GtkWidget *labelCarroAleatorio;
GtkWidget *labelCarroParams;
GtkWidget *labelSample;
GtkWidget *colorSelection;
GList *colorList = NULL;

GtkWidget *buttonCarroAleatorio;
GtkWidget *buttonCarroParams;

GtkWidget *inputDestinos;
    
static gint64 last_tick = 0;
static guint tick_cb = 0;
static guint size =32;

static GtkWidget *drawing;


static void on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    
    draw_background(cr);
    
   
} // on_draw


static gboolean on_tick (gpointer user_data) {
    gint64 current = g_get_real_time ();
    gboolean changed = FALSE;
    if ((current - last_tick) < (1000/ FPS)) {
        last_tick = current;
        return G_SOURCE_CONTINUE;
    }

    gtk_widget_queue_draw_area(drawing, 0, 0, WIDTH, HEIGTH);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}


static void validate_data(GtkWidget *widget, gpointer data){
    const gchar *destinos;
    int length;
    int active;
    destinos = gtk_entry_get_text(GTK_ENTRY(inputDestinos));
    length = gtk_entry_get_text_length(GTK_ENTRY(inputDestinos));
    active = gtk_combo_box_get_active(GTK_COMBO_BOX(colorSelection));

    if(length > 0 && active > 0){
    	gtk_widget_set_sensitive(buttonCarroParams, true);
    }else{
	gtk_widget_set_sensitive(buttonCarroParams, false);
    }
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}





//******************************************************************************
// ******************* MAIN ****************************************************
//*****************************************************************************

int main(int argc, char *argv[]) {

	
    gtk_init(&argc, &argv);
    GError * error = NULL;

    if (error) {
        printf("%s\n", error->message);
    }

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGTH);
    gtk_window_set_title(GTK_WINDOW(window), "SOA");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    
    drawing = gtk_drawing_area_new();
    gtk_fixed_put(GTK_FIXED(fixed), drawing, 0, 0);
    gtk_widget_set_size_request(drawing, WIDTH_DA, HEIGTH_DA); 
    g_signal_connect(drawing, "draw", G_CALLBACK(on_draw), NULL);
    
    gtk_widget_show_all(window);
    
    tick_cb = g_timeout_add(1000 / FPS / 2, (GSourceFunc) on_tick, GINT_TO_POINTER(size)); 
        
    //initSemaphoreBridges();

    gtk_main();

    
    return 0;
} 
