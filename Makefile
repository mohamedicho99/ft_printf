NAME = libftprintf.a
CC = cc
HEADER = ft_printf.h
SRC = ft_printf.c ft_puthex.c ft_strlen.c ft_putchar.c ft_calloc.c \
	  ft_putnbr.c ft_putnbr_un.c
FLAGS = -Werror -Wextra -Wall
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

# have another one makefile to use with other flags like fsanitize=address
# make -f custom_makefile_name
# look up everything in this make file again
