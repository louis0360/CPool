SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libbtree.a

all:	$(NAME)

$(NAME):	$(OBJ)
	cd ./lib/my&&make
	ar rc $(NAME) $(OBJ) ./lib/my/*.o

clean:
		rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
