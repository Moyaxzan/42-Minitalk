CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER_SOURCE = src/server.c

CLIENT_SOURCE = src/client.c

SERVER_OBJECT = $(SERVER_SOURCE:.c=.o)

CLIENT_OBJECT = $(CLIENT_SOURCE:.c=.o)

SERVER_EXECUTABLE = server

CLIENT_EXECUTABLE = client

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

MAKE = make

RMFLAGS = -f

all: $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

$(SERVER_EXECUTABLE): $(SERVER_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_EXECUTABLE): $(CLIENT_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm $(RMFLAGS) $(SERVER_OBJECT) $(CLIENT_OBJECT)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm $(RMFLAGS) $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

re: fclean all

.PHONY: all clean fclean
