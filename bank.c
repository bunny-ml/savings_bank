 
#include <gtk/gtk.h>

static void app_activate ( GtkApplication *app , gpointer user_data){
	// declaration of widgets 
	GtkWidget *window;
	GtkWidget *header;
	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *vbox;
	GtkWidget *hbox;

	entry1 = gtk_entry_new();
	entry2 = gtk_entry_new();
	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL , 10);
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 10);

	// window and header
	window = gtk_application_window_new(app);
	header = gtk_header_bar_new();
	
	// vertical box
	gtk_window_set_child(GTK_WINDOW(window), vbox);
	
	// inputs alignments 
	gtk_widget_set_hexpand(entry1, TRUE);
	gtk_widget_set_hexpand(entry2, TRUE);
	gtk_widget_set_halign(entry1 , GTK_ALIGN_CENTER);
	gtk_widget_set_halign(entry2, GTK_ALIGN_CENTER);

	// horizontal box
    gtk_box_append(GTK_BOX(hbox), entry1);
    gtk_box_append(GTK_BOX(hbox) , entry2);

	// horizontal box align and margins 
	gtk_widget_set_margin_top(hbox , 15);
	
	// virtual box alignments 
	gtk_box_append(GTK_BOX(vbox) , hbox);

	// placeholders 
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry1), "product name");
	gtk_entry_set_placeholder_text(GTK_ENTRY(entry2), "Price");

	

	// title and other
	gtk_window_set_title (GTK_WINDOW (window) , "Savings app , your personal goal book");
	gtk_window_set_default_size (GTK_WINDOW (window) , 700 , 500);
	gtk_window_set_resizable (GTK_WINDOW (window) , TRUE);

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
