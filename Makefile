##
## EPITECH PROJECT, 2021
## B-PSU-400-PAR-4-1-malloc-nicolas.allain
## File description:
## Makefile
##

CC	=	gcc

LIB	=	src/malloc.c	\
		src/free.c	\
		src/realloc.c	\
		src/calloc.c	\
		src/realloc_array.c	\
		src/pagination.c	\
		src/get_node.c		\

OBJ	=	$(LIB:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	=	-W -Wall -fPIC

CPPFLAGS	=	-I include/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -fPIC -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
