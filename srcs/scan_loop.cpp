#include "monitor.hpp"

// void	loop(Glib::RefPtr<Gio::ListStore<Server>> server_list)
// {
// 	Glib::RefPtr<Server>	tmp_server;
// 	tmp_server = server_list->get_item(0);
// 	if (!tmp_server)
// 	{
// 		std::cerr << "wut" << std::endl;
// 		return;
// 	}

// 	while (true)
// 	{
// 		std::this_thread::sleep_for(std::chrono::seconds(2));
// 		std::cout << "Activation" << std::endl;
// 	}
// }

bool	loop(Glib::RefPtr<Gio::ListStore<Server>> server_list)
{
	Glib::RefPtr<Server>	tmp_serv = server_list->get_item(0);
	Glib::ustring			old_name = tmp_serv->get_name();
	std::cout << "Old name : " << old_name << std::endl;
	tmp_serv->set_name(old_name + " a");
	std::cout << "New name : " << tmp_serv->get_name() << std::endl;
	return (true);
}