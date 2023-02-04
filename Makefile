##
## EPITECH PROJECT, 2022
## Huffman_coding
## File description:
## Makefile
##

SRC	=	source/huffman.c\
		source/file_io.c\
		source/huffman_node.c\
		source/huffman_tree.c\
		source/byte_occurence.c\
		source/pair.c

OBJ	=	$(SRC:.c=.o)

NAME	=	huff_compress

LDFLAGS	=	-L. -lgencds

CFLAGS = -Wall -Wextra

CPPFLAGS	=	-Iinclude -g3

all: $(NAME)

.o:
	$(CC) -c -o $< $@ $(CPPFLAGS) $(LDFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re clean
