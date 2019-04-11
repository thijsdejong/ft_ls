# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/14 10:45:58 by tde-jong       #+#    #+#                 #
#    Updated: 2019/04/11 14:32:05 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PROJECT = ft_ls
SRCS = main.c options.c parse.c helper.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib
	@echo "[+] $(PROJECT): compiling object files"
	@$(CC) -c $(FLAGS) $(SRCS)
	@echo "[+] $(PROJECT): creating $(NAME) ..."
	@$(CC) $(FLAGS) $(SRCS:.c=.o) -o $(NAME) -L libft -lft

lib:
	@echo "[o] $(PROJECT): compiling library ..."
	@make -C libft

clean:
	@echo "[o] $(PROJECT): cleaning library ..."
	@make -C libft clean
	@echo "[-] $(PROJECT): removing object files"
	@rm -f $(SRCS:.c=.o)


fclean: clean
	@echo "[o] $(PROJECT): fcleaning library ..."
	@make -C libft fclean
	@echo "[-] $(PROJECT): removing binary"
	@rm -f $(NAME)

re: fclean all

test_norm:
	@make re
	@echo "[+] $(PROJECT): cloning norminette+ ..."
	@git clone https://github.com/thijsdejong/codam-norminette-plus ~/norminette+
	@echo "[o] $(PROJECT): running norminette+ ..."
	@sh ${TRAVIS_BUILD_DIR}/norminette.sh

test_42fc:
	@make re
	@echo "[+] $(PROJECT): cloning 42FileChecker ..."
	@git clone https://github.com/jgigault/42FileChecker ~/42FileChecker
	@echo "[o] $(PROJECT): running 42FileChecker ..."
	@cd ~/42FileChecker && bash ./42FileChecker.sh --project "ft_ls" \
	--path "${TRAVIS_BUILD_DIR}" --no-norminette

build:
	@make
	@make clean
	@echo "DONE"
