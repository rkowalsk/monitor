#pragma once

#include "monitor.hpp"

class Server : public Glib::Object
{
	public:
		Server();
		~Server();

	protected:
		// void	on_button_clicked();

	private:
		Glib::ustring	name;
		Glib::ustring	ip;
		Glib::ustring	login;
		Glib::ustring	password;
		bool			is_reachable; // Quand testé avec Test-WSMan
		bool			is_saved; // Statut de la sauvegarde
};
