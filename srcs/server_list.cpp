#include "monitor.hpp"

// Fonction qui remplie la server_list avec le fichier CSV
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	(void) list_path;
	(void) server_list;
	return (0);
}