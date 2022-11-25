##
## EPITECH PROJECT, 2022
## Huffman_coding
## File description:
## Makefile
##

SRC	=	source/main.c\
		source/file_io.c

OBJ	=	$(SRC:.c=.o)

NAME	=	huffman

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re clean
