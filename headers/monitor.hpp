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
#include <gtkmm/image.h>
#include <functional>
#include <chrono>
#include <thread>
#include <glibmm/main.h>
#include <cstdlib>

#include "Server.hpp"
#include "Config.hpp"

#define	CONFIG_FILE_PATH "monitor.conf"
#define CSV_DELIMITER ','
// à modifier pour modifier les icones de sauvegardes et de connexion
#define SAVED_ICON "drive-harddisk-symbolic"
#define UNSAVED_ICON "task-past-due-symbolic"
#define REACHABLE_ICON "network-transmit-receive-symbolic"
#define UNREACHABLE_ICON "network-error-symbolic"

class	Server;
struct	Config;

// fonctions
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list);
bool	loop(Glib::RefPtr<Gio::ListStore<Server>> server_list);
bool	get_config(Config &config);
