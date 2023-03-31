#include "monitor.hpp"

//note: view.signal_activate pour quand la row est double clickée

bool	prepare_view(Glib::RefPtr<Gtk::Builder>	builder,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	Glib::RefPtr<Gtk::NoSelection>				selection_model;
	Glib::RefPtr<Gtk::SignalListItemFactory>	factory;
	Gtk::ListView								*view;

	view = builder->get_widget<Gtk::ListView>("ServerList");
	if (!view)
	{
		std::cerr << "Unable to get ServerList" << std::endl;
		return (1);
	}

	selection_model = Gtk::NoSelection::create(server_list);
	factory = Gtk::SignalListItemFactory::create();

	factory->signal_setup().connect(sigc::ptr_fun(&Server::on_setup));
	factory->signal_bind().connect(sigc::ptr_fun(&Server::on_bind));

	view->set_model(selection_model);
	view->set_factory(factory);
	return (0);
}

void	on_app_activate(Glib::RefPtr<Gtk::Application> &app,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	Glib::RefPtr<Gtk::Builder>	builder;
	Gtk::Window					*main_window;

	builder = Gtk::Builder::create_from_file("ui/monitor.ui");

	if (prepare_view(builder, server_list))
		exit(1);

	main_window = builder->get_widget<Gtk::ApplicationWindow>("MainWindow");
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