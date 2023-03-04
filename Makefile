NAME = libftprintf.a

SRC = ft_do_char.c ft_do_flags.c ft_do_hex.c ft_do_int.c ft_do_percent.c\
	ft_do_pointer.c ft_do_string.c ft_do_uint.c ft_do_width.c\
	ft_isdigit.c ft_printf.c ft_putchar.c ft_strdup.c ft_which_stuf.c\
	ft_strlen.c ft_utl_base.c 

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

ARSR = ar -sr

REMOVE = rm -f

all : $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(SRC)
	$(ARSR) $(NAME) $(OBJ)

clean: 
	$(REMOVE) $(OBJ)

fclean: 
	$(REMOVE) $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re