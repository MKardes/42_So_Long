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

norm:
	@echo "\033[0;94m\n\tNORMİNETTES\n\n"
	@echo "\033[0;92mFt_Printf\033[0;39m\n"
	norminette $(F_PRINT)
	@echo "\n\033[0;92mGet_Next_Line\033[0;39m\n"
	norminette $(F_LINE)
	@echo "\n\033[0;92mThis Directiory\033[0;39m\n"
	norminette *.c *.h

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
