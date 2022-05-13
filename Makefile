SRC_S	= 	server.c  my_libft.c
SRC_C		= 	client.c my_libft.c

OBJS_S	=	${SRC_S:.c=.o}
OBJS_C	=	${SRC_C:.c=.o}

CC		=	cc

CFLAGS 	= 	-Wall -Werror -Wextra

RM 		=	rm -f

LIBS	=	minitalk.h

SERVER	=	server

CLIENT	=	client


all:	$(SERVER) $(CLIENT)


$(SERVER)	: $(LIBS) $(OBJS_S)
	$(CC) $(CFLAGS)  $(OBJS_S)  -o $(SERVER)

$(CLIENT)	: $(LIBS) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C)  -o $(CLIENT)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# test :
# 	$(CC) main.c $(NAME)
# 	./a.out
clean:
	$(RM) $(OBJS_C) $(OBJS_S)

fclean:	clean
	$(RM) $(CLIENT) $(SERVER)

re:			fclean	$(CLIENT) $(SERVER)

.PHONY:	all clean fclean re