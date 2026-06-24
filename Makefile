NAME = exame
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = auth.c \
	avl.c \
	main.c \
	presentation.c \
	file.c \
	heap.c \
	huffman.c \
	storage.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
