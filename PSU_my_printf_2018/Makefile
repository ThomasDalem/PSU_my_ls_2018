##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c		    \
		my_putchar.c		    \
		my_putstr.c		    \
		my_put_nbr.c		    \
		my_printf_flags_display.c   \
		my_printf_flags_display2.c  \
		my_printf_flags_display3.c  \
		my_revstr.c

TESTSRC	=	tests/test_my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -c -Wall $(SRC)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f unit_tests

re: fclean all
