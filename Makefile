NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = push_swap.h

#Colors
GREEN = \033[0;92m

SRC_FILES = ft_split push_swap push_swap_utils push_swap_utils1 \
	    radix_sort the_algo the_rules the_rules1

SRC = $(addsuffix .c, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)
	@echo "$(GREEN) $(NAME) is ready!"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
