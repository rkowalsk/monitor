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