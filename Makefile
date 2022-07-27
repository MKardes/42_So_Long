NAME = libmlx.a
LIBX = mlx/libmlx.a
PRINT = Others/ft_printf/libftprintf.a
LINE = Others/Get_Next_Line/get_next_line.a
MINILIB = mlx
PRINTF = Others/ft_printf
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
PRG = so_long

all: $(NAME)
	gcc $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LINE) *.c -o $(PRG)
	@echo "Mission FAİLED SUCCESSFULLY"

$(NAME): $(LIBX) $(PRINT)
	cp $(LIBX) .
	rm -rf $(LIBX) libftprintf.a

$(LIBX): $(MINILIB)
	make -C $(MINILIB)

$(PRINT): $(PRINTF)
	make -C $(PRINTF)

bonus:

clean:
	make clean -C $(PRINTF)
	make clean -C $(MINILIB)

fclean: clean
	make fclean -C $(PRINTF)
	rm -rf so_long *.a

re: fclean all

.PHONY: clean re fclean all
