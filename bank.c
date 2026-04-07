 #include <gtk/gtk.h>


typedef struct {
	GtkWidget *vbox_container;
	int row_count;

} Appdata;

static void add_product_row(GtkWidget *add_btn , gpointer user_data) {
	Appdata *data = (Appdata *)user_data;
	data-> row_count++;

	GtkWidget *hbox;
	GtkWidget *label;
	GtkWidget *name_entry;
	GtkWidget *price_entry;

	// horizontal box 
	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 15);
	gtk_widget_set_margin_bottom(hbox, 5);

	// label or numbers 
	char *num_text = g_strdup_printf("%d.", data->row_count);
	label = gtk_label_new(num_text);
	gtk_editable_set_width_chars(GTK_EDITABLE(label),3);
	g_free(num_text);

	//input entry
	name_entry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(name_entry), "Product Name");
	gtk_widget_set_hexpand(name_entry, TRUE);

	price_entry = gtk_entry_new();
	gtk_entry_set_placeholder_text(GTK_ENTRY(price_entry), "Price");
	gtk_editable_set_width_chars(GTK_EDITABLE(price_entry), 10);

	// append
	gtk_box_append(GTK_BOX(hbox),label);
	gtk_box_append(GTK_BOX(hbox), name_entry);
	gtk_box_append(GTK_BOX(hbox), price_entry);
	
	gtk_box_append(GTK_BOX(data->vbox_container), hbox);
}



static void app_activate ( GtkApplication *app , gpointer user_data){
	// declaration of widgets 
	GtkWidget *window;
	GtkWidget *layout_main;
	GtkWidget *add_btn;
	GtkWidget *minus_btn;
	GtkWidget *save_btn;
	GtkWidget *open_btn;
	GtkWidget *product_name;
	GtkWidget *product_price;
	GtkWidget *scrolled;

	// window 
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Savings Bank");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);

	// main layout 
	layout_main = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_widget_set_margin_top(layout_main, 15);
	gtk_widget_set_margin_bottom(layout_main, 15);
	gtk_window_set_child(GTK_WINDOW(window), layout_main);

	// add button
	add_btn = gtk_button_new_from_icon_name("list-add-symbolic");
	gtk_box_append(GTK_BOX(layout_main), add_btn);

	// scrolled
	scrolled = gtk_scrolled_window_new();
	gtk_widget_set_vexpand(scrolled , TRUE);
	gtk_box_append(GTK_BOX(layout_main), scrolled);

	// vertical box 
	Appdata *data = g_new(Appdata ,1);
	data->vbox_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	data->row_count =0;
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled), data->vbox_container);


	// button signal 
	g_signal_connect(add_btn, "clicked" , G_CALLBACK(add_product_row), data);

	// automatic first row
	add_product_row(NULL, data);

	gtk_window_present(GTK_WINDOW(window));
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
