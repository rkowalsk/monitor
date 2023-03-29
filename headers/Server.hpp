#pragma once

#include "monitor.hpp"

class Server : public Glib::Object
{
	public:
		Server();
		~Server();

		Glib::ustring	get_name(void) const;
		Glib::ustring	get_ip(void) const;
		Glib::ustring	get_login(void) const;
		Glib::ustring	get_password(void) const;
		bool			get_reachable(void) const;
		bool			get_saved(void) const;

		void			set_name(Glib::ustring const &new_name);
		void			set_ip(Glib::ustring const &new_ip);
		void			set_login(Glib::ustring const &new_login);
		void			set_password(Glib::ustring const &new_password);
		void			set_reachable(bool const &is_reachable);
		void			set_saved(bool const &is_saved);


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
