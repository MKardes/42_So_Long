FILE1 = ../ft_printf
FILE2 = ../Get_Next_Line
FILE3 = ../../Bonus
FILE4 = ../../Game
FILE5 = ../Norm
FILE6 = ../Norm
FILE7 = ../Norm
FILE8 = ../Norm
FILE9 = ../Norm
NORM = prg/norm.exe
LAST = prg/test.exe

all:
	@echo "\033[0;93m\nNorminette:\033[0;39m\n"
	@mkdir Txt
	@norminette $(FILE1) | cut -d' ' -f2 | cat > Txt/test1.txt
	@$(NORM) Txt/test1.txt $(FILE1) | cat > test1.txt
	@norminette $(FILE2) | cut -d' ' -f2 | cat > Txt/test2.txt
	@$(NORM) Txt/test2.txt $(FILE2) | cat > test2.txt
	@norminette $(FILE3) | cut -d' ' -f2 | cat > Txt/test3.txt
	@$(NORM) Txt/test3.txt $(FILE3) | cat > test3.txt
	@norminette $(FILE4) | cut -d' ' -f2 | cat > Txt/test4.txt
	@$(NORM) Txt/test4.txt $(FILE4) | cat > test4.txt
	@norminette $(FILE5) | cut -d' ' -f2 | cat > Txt/test5.txt
	@$(NORM) Txt/test5.txt $(FILE5) | cat > test5.txt
	@norminette $(FILE6) | cut -d' ' -f2 | cat > Txt/test6.txt
	@$(NORM) Txt/test6.txt $(FILE6) | cat > test6.txt
	@norminette $(FILE7) | cut -d' ' -f2 | cat > Txt/test7.txt
	@$(NORM) Txt/test7.txt $(FILE7) | cat > test7.txt
	@norminette $(FILE8) | cut -d' ' -f2 | cat > Txt/test8.txt
	@$(NORM) Txt/test8.txt $(FILE8) | cat > test8.txt
	@norminette $(FILE9) | cut -d' ' -f2 | cat > Txt/test9.txt
	@$(NORM) Txt/test9.txt $(FILE9) | cat > test9.txt
	@$(LAST) *.txt
	@rm -rf *.txt Txt

clean:
	rm -rf *.txt Txt
