##
## EPITECH PROJECT, 2022
## Huffman_coding
## File description:
## Makefile
##

SRC	=	source/main.c\
		source/file_io.c\
		source/huffman_node_array.c\
		source/huffman_node.c\
		source/huffman_tree.c\
		source/byte_occurence.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	huff

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-Iinclude -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re clean
