#include "Server.hpp"
#include <iostream>

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