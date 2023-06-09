NAME = moniteur.exe

HEADERS_DIR = headers

HEADERS =	headers/Server.hpp \
			headers/monitor.hpp

SRCS =	srcs/main.cpp \
		srcs/parse_csv.cpp \
		srcs/scan_loop.cpp \
		srcs/get_config.cpp \
		srcs/Server.cpp

PKG_FLAGS = -Wall -Wextra -Werror $(shell pkg-config gtkmm-4.0 --cflags --libs)

.PHONY: all fclean re

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	g++ $(SRCS) $(PKG_FLAGS) -I$(HEADERS_DIR) -o $@

fclean:
	rm -f $(NAME)

re: fclean all