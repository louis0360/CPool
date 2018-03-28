SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	grep

all:	$(NAME)

$(NAME):	$(OBJ)
	cd ../lib/my/&&make
	gcc -o $(NAME) $(OBJ) -I../include -L../lib/my -lmy

clean:
		rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
