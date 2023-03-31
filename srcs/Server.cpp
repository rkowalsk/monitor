#include "monitor.hpp"

// Constructeur par défaut
Server::Server() : name("default"), ip("1.2.3.4"), login("default"),
	password("default"), is_reachable(false), is_saved(false)
{
}

Server::~Server()
{
}

// void Server::on_button_clicked()
// {
// 	std::cout << "Amogus" << name << std::endl;
// }

Glib::ustring	Server::get_name(void) const
{
	return (name);
}

Glib::ustring	Server::get_ip(void) const
{
	return (ip);
}

Glib::ustring	Server::get_login(void) const
{
	return (login);
}

Glib::ustring	Server::get_password(void) const
{
	return (password);
}

bool			Server::get_reachable(void) const
{
	return (is_reachable);
}

bool			Server::get_saved(void) const
{
	return (is_saved);
}

void			Server::set_name(Glib::ustring const &new_name)
{
	name = new_name;
}
void			Server::set_ip(Glib::ustring const &new_ip)
{
	ip = new_ip;
}

void			Server::set_login(Glib::ustring const &new_login)
{
	login = new_login;
}

void			Server::set_password(Glib::ustring const &new_password)
{
	password = new_password;
}

void			Server::set_reachable(bool const &new_reachable)
{
	is_reachable = new_reachable;
}

void			Server::set_saved(bool const &new_saved)
{
	is_saved = new_saved;
}

void			Server::setup_labels(Gtk::Label *name, Gtk::Label *ip,
	Gtk::Label *login, Gtk::Label *password)
{
	name->set_justify(Gtk::Justification::LEFT);
	name->set_expand(true);
	name->set_width_chars(35);
	name->set_ellipsize(Pango::EllipsizeMode::END);
	ip->set_expand(true);
	ip->set_selectable(true);
	ip->set_width_chars(15);
	login->set_expand(true);
	login->set_selectable(true);
	password->set_expand(true);
	password->set_selectable(true);
}

void			Server::on_setup(Glib::RefPtr<Gtk::ListItem> const &list_item)
{
	auto	*box = Gtk::make_managed<Gtk::Box>();
	auto	*name = Gtk::make_managed<Gtk::Label>();
	auto	*ip = Gtk::make_managed<Gtk::Label>();
	auto	*login = Gtk::make_managed<Gtk::Label>();
	auto	*password = Gtk::make_managed<Gtk::Label>();
	setup_labels(name, ip, login, password);
	box->append(*name);
	box->append(*ip);
	box->append(*login);
	box->append(*password);
	box->set_expand(true);
	// box->set_halign(Gtk::Align::FILL);
	list_item->set_child(*box);
}

void			Server::on_bind(Glib::RefPtr<Gtk::ListItem> const &list_item)
{
	auto	server = std::dynamic_pointer_cast<Server>(list_item->get_item());
	if (!server)
	{
		std::cerr << "No server ?" << std::endl;
		return;
	}
	Gtk::Box	*box = dynamic_cast<Gtk::Box*>(list_item->get_child());
	if (!box)
	{
		std::cerr << "No box ?" << std::endl;
		return;
	}
	auto	name = dynamic_cast<Gtk::Label*>(box->get_first_child());
	if (!name)
	{
		std::cerr << "No name ?" << std::endl;
		return;
	}
	auto	ip = dynamic_cast<Gtk::Label*>(name->get_next_sibling());
	if (!ip)
	{
		std::cerr << "No ip ?" << std::endl;
		return;
	}
	auto	login = dynamic_cast<Gtk::Label*>(ip->get_next_sibling());
	if (!login)
	{
		std::cerr << "No login ?" << std::endl;
		return;
	}
	auto	password = dynamic_cast<Gtk::Label*>(login->get_next_sibling());
	if (!password)
	{
		std::cerr << "No password ?" << std::endl;
		return;
	}
	name->set_markup("<b>" + server->name + "</b>");
	ip->set_markup(server->ip);
	login->set_markup(server->login);
	password->set_markup(server->password);
}
