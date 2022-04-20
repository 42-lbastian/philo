DIRSRC		= ./srcs/

DIRINC		= ./includes/

DIROBJ		= ./objs/

SRC			=	atoi \
				init \
				main \
				thread \
				time \
				ft_str_is_numeric\

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= philo_one

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -pthread

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -I ${DIRINC} -o ${NAME} ${OBJS} ${LIBFLAGS}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
