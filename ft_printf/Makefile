NAME= libftprintf.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f
LDFLAGS= -L.
LDLIBS= -lft
SRC= ft_printf.c ft_putchar.c ft_puthexa.c ft_puthexamem.c ft_putnbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean
