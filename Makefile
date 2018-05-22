##
## EPITECH PROJECT, 2017
## Makefile_TL 
## my_stumper2_main
##
##

SRC=	main.c	\
	get_info/get_info.c	\

OBJ=	$(SRC:.c=.o)

CFLAGS= -Wextra -Wall -W -g -g3

NAME= colle

all: $(NAME)

$(NAME):	$(OBJ)
		-cc -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
