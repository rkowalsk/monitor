#include "monitor.hpp"

bool	store_line(Config &config, std::string const &key,
	std::string const &value)
{
	if (key == "csv_path")
	{
		config.csv_path = value;
		return (0);
	}
	else if (key == "backup_ip")
	{
		config.backup_ip = value;
		return (0);
	}
	else if (key == "backup_port")
	{
		config.backup_port = value;
		return (0);
	}
	else if (key == "backup_login")
	{
		config.backup_login = value;
		return (0);
	}
	else if (key == "backup_password")
	{
		config.backup_password = value;
		return (0);
	}
	else if (key == "backup_path")
	{
		config.backup_path = value;
		return (0);
	}
	return (1);
}

std::string	trim_whitespaces(std::string &input)
{
	std::string			output;
	std::istringstream	is_input(input);


	is_input >> std::ws >> output;
	return (output);
}

bool	parse_line(Config &config, std::string line)
{
	std::istringstream	is_line(line);
	std::string 		key;
	std::string			value;
	if(std::getline(is_line, key, '='))
	{
		if(std::getline(is_line, value))
			store_line(config, trim_whitespaces(key), trim_whitespaces(value));
	}
	return (false);
}

bool	get_config(Config &config)
{
	std::string		line;
	std::ifstream	source;

	source.open(CONFIG_FILE_PATH);
	if (source.fail())
	{
		std::cerr << "Impossible d'ouvrir le fichier de config" << std::endl;
		return (1);
	}
	while (std::getline(source, line))
	{
		if (parse_line(config, line))
			return (1);
	}
	return (0);
}