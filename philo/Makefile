NAME	=	philo

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -pthread -fsanitize=thread -g

SRCS	=	action.c \
			ft_free.c \
			ft_time.c \
			init_philo.c \
			main.c \
			routine.c \
			utils.c \
			lock.c

DIR_INC	=	include
DIR_SRC	=	src

RM	=	rm -rf

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

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
	@norminette $(SRCS)
	@echo "-------------------------------------------\n"
