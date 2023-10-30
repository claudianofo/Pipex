NAME = pipex
SOURCES = pipex.c utils.c split_pipex.c

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
CFLAGS = -Wall -Werror -Wextra -g3 -Ilibft

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -Llibft -lft -o $(NAME) 

%.o: %.c $(LIBFT)
	cc $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make all -C ./libft

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re