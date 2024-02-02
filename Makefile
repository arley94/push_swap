# NAMES
NAME = push_swap

# LIBS
LIBS_DIR = libs/
FT_DIR = libft/libft.a
FTPRINTF_DIR = libftprintf/libftprintf.a
LIBFT = $(addprefix $(LIBS_DIR), $(FT_DIR))
LIBFTPRINTF = $(addprefix $(LIBS_DIR), $(FTPRINTF_DIR))

# SOURCE FILES
SRC_DIR = src/
SRC_FILES = 	main.c 						\
				parse.c 					\
				stack_utils.c				\
				ft_atoi_special.c			\
				error_free.c				\
				push_command.c				\
				swap_command.c				\
				rotate_command.c			\
				reverse_rotate_command.c	\
				small_sort.c				\
				big_sort_utils.c			\
				big_sort.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_FILES = $(SRC:.c=.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3
INCLUDE = -I includes
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	@make -C libs/libft
	@make -C libs/libftprintf
	@echo "$(PINK)Compiling PUSH_SWAP.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) $(INCLUDE) $(LIBFT) $(LIBFTPRINTF) -o $(NAME) 
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -C libs/libft
	@make clean -C libs/libftprintf
	$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -C libs/libft
	@make fclean -C libs/libftprintf
	$(RM) $(NAME)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all bonus clean fclean re