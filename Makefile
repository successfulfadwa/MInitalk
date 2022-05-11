SRC		= 	server.c client.c my_libft.c

OBJS	=	${SRC:.c=.o}

CC		=	cc

CFLAGS 	= 	-Wall -Werror -Wextra

RM 		=	rm -f

LIBS	=	libft.h

SERVER	=	server

CLIENT	=	client

CADD	=	my_libft.c

ADD		=	$(CADD:.c=.o)

all:	$(SERVER)

server: $(LIBS) server.o
	$(CC) $(CFLAGS) server.o $(ADD) -o $@

client: $(LIBS) client.o
	$(CC) $(CFLAGS) client.o $(ADD) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# test :
# 	$(CC) main.c $(NAME)
# 	./a.out
clean:
	$(RM) $(OBJS)

fclean:		clean
		$(RM) $(CLIENT) $(SERVER)

re:			fclean	$(CLIENT) $(SERVER)

.PHONY:	all clean fclean re