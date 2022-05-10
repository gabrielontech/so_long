INC=/usr/include

PRINTF = $(addprefix ft_printf/,ft_printf.c ft_putchar.c ft_puthexa.c ft_puthexamem.c ft_putnbr.c ft_putstr.c )
CK = $(addprefix checkers/, checker.c is_cep_checker.c map_content_checkers.c valid_map_checker.c )   
PM = $(addprefix prog_management/, free_style.c error.c )
LIBFT = $(addprefix libft/, ft_strncmp.c ft_split.c ft_putstr_fd.c )
GNL = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c )
DISPLAY = $(addprefix displayers/, display_xpm_extends.c display_xpm.c displayer.c ) 

INCLIB=$(INC)/../lib

CFLAGS= -I$(INC) -I./minilibx-linux -g

NAME= so_long
SRC = main.c $(PRINTF) $(CK) $(PM) $(GNL) $(LIBFT) $(DISPLAY)
OBJ = $(SRC:%.c=%.o)
RM = rm -rf


LFLAGS = -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm 

CC= gcc
LFLAGS += -lbsd

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	$(RM) $(OBJ) *~ core *.core

fclean:
	$(RM) $(NAME) $(OBJ) *~ core *.core


re: clean all