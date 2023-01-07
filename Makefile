NAME=minishell


CC=gcc
CFLAGS=#-Wall -Werror -Wextra
SRCS=#SRC list
LIBFT= -L./libft/ -I./libft/ -lft
INC= -I./inc/
TEST_FILE=run_command.c

RM=rm -rf


# Color
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
RESET=\033[0m

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	LREAD_DIR = -L/usr/local/lib -I/usr/local/include/ -lreadline 
else 
	LREAD_DIR = -L/usr/local/opt/readline -I/usr/local/opt/readline/include -lreadline
endif

INC=-iquote ./include $(LREAD_DIR) $(LIBFT)

all: libft
	@printf "Now you complie in \e[1;34m$(UNAME)\e[0m\n"
	@ echo "$(RED)"
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(INC) main.c $(LREAD_DIR) $(LIBFT) -o $(NAME)
=======
	$(CC) $(CFLAGS) main.c $(INC) -o $(NAME)
>>>>>>> b1fc285ea95fe03829023e384f493ec983332eb4
	@ echo "$(RESET)"

test: libft
	@printf "$(RED)Run test$(RESET)\n"
	$(CC) $(CFLAGS) $(TEST_FILE) $(INC) -o $(NAME)
	@printf "$(GREEN)Result test$(RESET)\n"
	@./$(NAME)
	@echo "Exit with  $(.SHELLSTATUS)"

libft:
	@echo "Start Create $(BLUE)Lib-ft$(RESET)"
	@make -C ./libft

clean:
	@make -C ./libft clean
	@$(RM) $(OBJ)
	@$(RM) *.dSYM

fclean: clean
	@make -C ./libft clean
	@ echo "$(RED)Remove Libft $(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)Remove minishell $(RESET)"

re: fclean all

.PHONY: all libft clean fclean re
