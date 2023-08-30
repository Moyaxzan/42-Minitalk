######   Mandatory part   ######
NAME = minitalk

SERVER_EXECUTABLE = server

CLIENT_EXECUTABLE = client

SERVER_SOURCE = src/server.c

CLIENT_SOURCE = src/client.c

CLIENT_OBJECT = $(CLIENT_SOURCE:.c=.o)

SERVER_OBJECT = $(SERVER_SOURCE:.c=.o)

#######   Bonus part   #######

BONUS = bonuses

SERV_BONUS_EXE = server_bonus

CLI_BONUS_EXE = client_bonus

CLI_BONUS_SRC = src_bonus/client_bonus.c

SERV_BONUS_SRC = src_bonus/server_bonus.c

CLI_BONUS_OBJ = $(CLI_BONUS_SRC:.c=.o)

SERV_BONUS_OBJ = $(SERV_BONUS_SRC:.c=.o)

#####   Flags & stuff   ######

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

MAKE = make

RMFLAGS = -f

#######   Rules   #######

all: $(NAME)

$(NAME): $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

$(SERVER_EXECUTABLE): $(SERVER_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_EXECUTABLE): $(CLIENT_OBJECT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS)

$(BONUS): $(SERV_BONUS_EXE) $(CLI_BONUS_EXE)

$(SERV_BONUS_EXE): $(SERV_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLI_BONUS_EXE): $(CLI_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm $(RMFLAGS) $(SERVER_OBJECT) $(CLIENT_OBJECT) $(SERV_BONUS_OBJ) $(CLI_BONUS_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm $(RMFLAGS) $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE) $(CLI_BONUS_EXE) $(SERV_BONUS_EXE)

re: fclean all

.PHONY: all clean fclean bonus
