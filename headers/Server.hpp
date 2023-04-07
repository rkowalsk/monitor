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

		static void		on_setup(Glib::RefPtr<Gtk::ListItem> const &list_item);
		static void		on_bind(Glib::RefPtr<Gtk::ListItem> const &list_item);

		bool			is_reachable(void) const;
		// bool			is_bakced_up(void) const;

	protected:
		// void	on_button_clicked();

	private:
		static void		setup_labels(Gtk::Label *name, Gtk::Label *ip,
			Gtk::Label *login, Gtk::Label *password);
		static void		setup_icons(Gtk::Image *reachable, Gtk::Image *saved);

		Glib::ustring	name;
		Glib::ustring	ip;
		Glib::ustring	login;
		Glib::ustring	password;
};
