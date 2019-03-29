# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tde-jong <tde-jong@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/09 12:43:22 by tde-jong       #+#    #+#                 #
#    Updated: 2019/03/25 12:15:33 by tde-jong      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAGS=-Wall -Wextra -Werror

HFILES=-I includes/

SRC= ft_strcat.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strsub.c \
		ft_strtoupper.c \
		ft_strtrim.c \
		ft_atoi.c \
		ft_intlen.c \
		ft_intlen_base_uintmax.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isin.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_memcmp.c \
		ft_strcmp.c \
		ft_strequ.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memdel.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c

CFILES=$(SRC)

OFILES=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "[+] libft: compiling sources ..."
	@gcc $(FLAGS) -c $(CFILES) $(HFILES)
	@echo "[+] libft: generating $(NAME)"
	@ar rcs $(NAME) $(OFILES)

clean:
	@echo "[-] libft: cleaning extra files ..."
	@rm -f $(OFILES)
	@rm -f *~
	@rm -f \#*#
	@echo "[-] libft: removing 42FileChecker ..."
	@rm -rf 42FileChecker

fclean: clean
	@echo "[-] libft: removing $(NAME) ..."
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
	@cd ~/42FileChecker && bash ./42FileChecker.sh --project "libft" \
	--path "${TRAVIS_BUILD_DIR}" --no-norminette
