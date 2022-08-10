NAME = mlx/libmlx.a
CC = gcc
PRINT = Others/ft_printf/libftprintf.a
LINE = Others/Get_Next_Line/get_next_line.a
MINILIB = mlx
F_LINE = Others/Get_Next_Line
F_PRINT = Others/ft_printf
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
PRG = so_long

all: $(NAME)
	$(CC) $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LINE) *.c -o $(PRG)
	@echo "Mission FAİLED SUCCESSFULLY"

$(NAME): $(PRINT) $(LINE) $(MINILIB)
	make -C $(MINILIB)
	@echo "MAKE DONE!!"

$(PRINT): $(F_PRINT)
	make -C $(F_PRINT)

$(LINE): $(F_LINE)
	make -C $(F_LINE)

clean:
	make clean -C $(F_LINE)
	make clean -C $(F_PRINT)
	make clean -C $(MINILIB)

fclean: clean
	make fclean -C $(F_LINE)
	make fclean -C $(F_PRINT)
	rm -rf so_long *.a

re: fclean all

.PHONY: clean re fclean all
