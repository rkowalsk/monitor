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
#include <fstream>

#include "Server.hpp"

#define CSV_DELIMITER ','	

class Server;

// fonctions
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list);