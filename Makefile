NAME = push_swap

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -g
COMPILE = cc $(CFLAGS)
RM = rm -rf

SRC = main.c \
	moves/push.c \
	moves/rotate.c \
	moves/swap.c \
	sort/sort_init.c \
	sort/sort_three.c \
	sort/sort.c \
	utils/init.c \
	utils/ft_av_split.c \
	utils/dllst_utils.c \
	utils/generic_utils.c \
	utils/mod_libft.c
	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)
	echo "PUSH SWAP IS COMPILED"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	@$(RM) $(NAME)
	@echo "PUSH SWAP IS DELETED"

re: fclean all

%.o: %.C
	@$(COMPILE) -c $< -o $@

.PHONY: all clean fclean re

.SILENT: