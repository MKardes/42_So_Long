NAME = Others/mlx/libmlx.a
CC = gcc
PRINT = Others/ft_printf/libftprintf.a
LINE = Others/Get_Next_Line/get_next_line.a
MINILIB = Others/mlx
F_LINE = Others/Get_Next_Line
F_PRINT = Others/ft_printf
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
SO_LONG = so_long
BONUS = so_long_bonus
SRCS = Game/*.c
B_SRCS = Bonus/*.c
NORM = Others/Norm

all: $(NAME) $(SO_LONG)

$(SO_LONG) : $(PRINT) $(LINE) $(SRCS)
	make -C $(NORM)
	$(CC) $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LINE) $(SRCS) -o $(SO_LONG)
	@echo "Mission FAİLED SUCCESSFULLY"

run: bonus
	./$(BONUS) Maps/map_B1.ber

bonus: $(NAME) $(BONUS) 
	
$(BONUS): $(PRINT) $(LINE) $(B_SRCS)
	make -C Others/Norm
	$(CC) $(LFLAGS) $(FLAGS) $(NAME) $(PRINT) $(LINE) $(B_SRCS) -o $(BONUS)
	@echo "Bonus Succeed"

$(NAME): $(MINILIB)
	make -C $(MINILIB)
	@echo "\nMLX Done!!"

$(PRINT): $(F_PRINT)
	make -C $(F_PRINT)
	@echo "\nMLX Done!!"

$(LINE): $(F_LINE)
	make -C $(F_LINE)
	@echo "\nGet_Next_Line Done!!"

norm:
	norminette Others/ft_printf Others/Get_Next_Line Bonus Game

clean:
	make clean -C $(NORM)
	make clean -C $(F_LINE)
	make clean -C $(F_PRINT)
	make clean -C $(MINILIB)

fclean: clean
	make fclean -C $(F_LINE)
	make fclean -C $(F_PRINT)
	rm -rf so_long so_long_bonus *.a

re: fclean all

.PHONY: clean re fclean all
