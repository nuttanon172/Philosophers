NAME	=	philo

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -I$(DIR_INC)

SRCS	=	

DIR_INC	=	include
DIR_SRC	=	src

RM	=	rm -rf

$(NAME):
	@$(CC) $(CFLAGS) $(addprefix $(DIR_SRC)/, $(SRCS)) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(NAME)
		@echo "Philo has Removed"


fclean:
		@$(RM) $(NAME)
		@echo "Philo has Removed"

re: fclean all

norm:
	@echo "------------------- Philo -------------------"
	@norminette $(DIR_INC) $(DIR_SRC)
	@echo "-------------------------------------------\n"