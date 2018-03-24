SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include

clean:
		rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re:	fclean all
