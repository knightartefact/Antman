##
## EPITECH PROJECT, 2022
## Huffman_coding
## File description:
## Makefile
##

SRC	=	source/main.c\
		source/file_io.c\
		source/huffman_node.c\
		source/huffman_tree.c\
		source/byte_occurence.c\
		source/huffman_node_list.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	huff_compress

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-Iinclude -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re clean
