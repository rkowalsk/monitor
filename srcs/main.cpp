#include "monitor.hpp"

void	on_app_activate(Glib::RefPtr<Gtk::Application> &app,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	auto builder = Gtk::Builder::create_from_file("ui/monitor.ui");
	(void) server_list;

	Gtk::Window *main_window = builder->get_widget<Gtk::ApplicationWindow>(
		"MainWindow");
	if (!main_window)
	{
		std::cerr << "Unable to get MainWindow" << std::endl;
		exit(1);
	}

	app->add_window(*main_window);
	main_window->set_visible(true);
}

int main(void)
{
	Glib::RefPtr<Gtk::Application> app;
	Glib::RefPtr<Gio::ListStore<Server>> server_list;

	app = Gtk::Application::create("fr.ace-electronic.monitor");
	server_list = Gio::ListStore<Server>::create();
	if (get_server_list("liste_serveurs.csv", server_list)) // remplit la server_list avec les serveurs du CSV
	{
		std::cerr << "Erreur lors de la récupération des serveurs dans le";
		std::cerr << "fichier 'liste_serveurs.csv'" << std::endl;
		exit(1);
	}

	app->signal_activate().connect([&app, &server_list] ()
			{ on_app_activate(app, server_list); }
		);
	app->run();

	return (0);
}