#pragma once

#include <glibmm/ustring.h>
#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <iostream>
#include <giomm/liststore.h>
#include <glibmm/ustring.h>

#include "Server.hpp"

class Server;

// fonctions
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list);