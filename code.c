
#include <gtk/gtk.h>

static void app_activate ( GtkApplication *app , gpointer user_data){
	GtkWidget *window;
	GtkWidget *header;
	GtkWidget *entry0 = gtk_entry_new();
	GtkWidget *entry1 = gtk_entry_new();
	GtkWidget *vbox0 = gtk_box_new(GTK_ORIENTATION_VERTICAL , 10);
	GtkWidget *vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL , 20);

	window = gtk_application_window_new(app);
	header = gtk_header_bar_new();

	gtk_window_set_child(GTK_WINDOW(window), vbox0);
	gtk_window_set_child(GTK_WINDOW(window), vbox1);
	// signal 
	g_signal_connect(entry0 , "activate" , G_CALLBACK(app_activate), NULL);
	g_signal_connect(entry1 , "activate" , G_CALLBACK(app_activate), NULL);

	gtk_entry_set_placeholder_text(GTK_ENTRY(entry0), "product name");
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry1), "price");
	
	// vbox and entry
	gtk_box_append(GTK_BOX(vbox0), entry0);
	gtk_box_append(GTK_BOX(vbox1), entry1);

	gtk_window_set_title (GTK_WINDOW (window) , "GTK4 APP");
	gtk_window_set_default_size (GTK_WINDOW (window) , 700 , 500);
	gtk_window_set_resizable (GTK_WINDOW (window) , TRUE);

	

	//gtk_window_set_child(GTK_WINDOW(window) , entry0);
	//gtk_window_set_child(GTK_WINDOW(window) , entry1);
	gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(header) , TRUE);
	gtk_window_set_titlebar(GTK_WINDOW(window), header);
	gtk_window_present (GTK_WINDOW (window));

	}

int main(int argc , char **argv) {

	GtkApplication *app;

	int status;		
		
	app = gtk_application_new("app.example" , G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app , "activate" , G_CALLBACK(app_activate) , NULL);
	status = g_application_run (G_APPLICATION (app) , argc , argv);
	g_object_unref(app);
	return status;
	 	
}
