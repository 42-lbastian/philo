NAME = philo

SRCS =	srcs/free.c \
		srcs/init.c \
		srcs/philo_actions.c \
		srcs/philo.c \
		srcs/thread.c \
		srcs/tools.c \
		srcs/tools_mili.c \
		srcs/tools_print.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -pthread -Wall -Wextra -Werror -O3

SFLAGS = -pthread -Wall -Wextra -Werror -O3 -fsanitize=thread

RM = rm -rf

all:	$(NAME)

$(NAME): ${OBJS}
	$(CC) -o $(NAME) $(CFLAGS) ${OBJS}

philo_s: ${OBJS}
	$(CC) -o $(NAME) $(SFLAGS) ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all philo_s clean fclean re
