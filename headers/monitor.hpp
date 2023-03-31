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
#include <gtkmm/noselection.h>
#include <gtkmm/signallistitemfactory.h>
#include <gtkmm/listview.h>
#include <gtkmm/listitem.h>
#include <gtkmm/label.h>
#include <functional>

#include "Server.hpp"

#define CSV_DELIMITER ','

class Server;

// fonctions
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list);