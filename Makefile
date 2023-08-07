CLIENT		=	client

SERVER		=	server

SRCS_SERV	=	src/server.c

SRCS_CLI	=	src/client.c

CC		=	cc

OBJS_SERV	=	$(SRCS_SERV:.c=.o)

OBJS_CLI	=	$(SRCS_CLI:.c=.o)

C_FLAGS		=	-Wall -Wextra -Werror

RM_FLAGS	= 	-f

LIBFT_DIR	=	./libft

LIBFT		=	$(LIBFT_DIR)/libft.a

MAKE		=	make

all		:	$(CLIENT) $(SERVER)

$(SERVER)	:	$(OBJS_SERV) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_SERV) -o $(SERVER)

$(CLIENT)	:	$(OBJS_CLI) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_CLI) -o $(CLIENT)

$(OBJS_SERV) %.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_CLI) %.o	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)	:
			$(MAKE) -C $(LIBFT_DIR)
clean		:
			$(MAKE) -C $(LIBFT_DIR) clean
			rm $(RM_FLAGS) $(OBJS_SERV) $(OBJS_CLI)

fclean		:	clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			rm $(RM_FLAGS) $(SERVER) $(CLIENT)

re		:	fclean all

.PHONY		:	all  clean fclean re
