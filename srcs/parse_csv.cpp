#include "monitor.hpp"

bool	csv_line_to_Server(Glib::ustring line, Server &new_server)
{
	std::vector<Glib::ustring>	param_list;

	// std::cout << "Début csv_line_to_server" << std::endl;
	size_t	i = 0;
	size_t	pos = 0;
	size_t	new_pos;
	while (i < 3)
	{
		new_pos = line.find(CSV_DELIMITER, pos);
		if (new_pos == Glib::ustring::npos) // vrai s'il manque une virgule
			return (1);
		param_list.push_back(line.substr(pos, new_pos - pos));
		i++;
		pos = new_pos + 1;
	}
	param_list.push_back(line.substr(pos));
	if (line.find(CSV_DELIMITER, pos) != Glib::ustring::npos) // vrai s'il y a une virgule de trop
		return (1);

	new_server.set_name(param_list[0]);
	new_server.set_ip(param_list[1]);
	new_server.set_login(param_list[2]);
	new_server.set_password(param_list[3]);
	// std::cout << "Fin csv_line_to_server" << std::endl;
	return (0);
}

void	print_Server(Server const & serv)
{
	std::cout << "[" << serv.get_name() << "] ";
	std::cout << "[" << serv.get_ip() << "] ";
	std::cout << "[" << serv.get_login() << "] ";
	std::cout << "[" << serv.get_password() << "]" << std::endl;
}

bool	fill_list_store(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	Server					*server;
	std::string				csv_line;
	std::ifstream			source;
	Glib::RefPtr<Server>	server_refptr;

	source.open(list_path.c_str());
	if (source.fail())
	{
		std::cerr << "Impossible d'ouvrir le fichier CSV" << std::endl;
		return (1);
	}

	std::getline(source, csv_line);
	while (std::getline(source, csv_line))
	{
		try
		{
			server = new Server();
		}
		catch (std::exception const & e)
		{
			std::cerr << "Erreur de mémoire: " << e.what() << std::endl;
			source.close();
			return (1);
		}

		if (csv_line_to_Server(csv_line.c_str(), *server))
		{
			std::cerr << "Erreur lors du parsing du CSV: ";
			std::cerr << "nombre de colonnes différent de 4 (délimiteur: '";
			std::cerr << CSV_DELIMITER << "')" << std::endl;
			delete server;
			source.close();
			return (1);
		}
		// print_Server(*server);
		server_refptr = Glib::make_refptr_for_instance<Server>(server);
		server_list->append(server_refptr);
	}
	source.close();
	return (0);
}

// Fonction qui remplie la server_list avec le fichier CSV
bool	get_server_list(Glib::ustring const &list_path,
	Glib::RefPtr<Gio::ListStore<Server>> &server_list)
{
	if (fill_list_store(list_path, server_list))
		return (1);	
	return (0);
}