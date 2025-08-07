NAME		=	philo

CC		=	cc

FLAGS		=	-Wall -Wextra -Werror
#ASAN		=	-fsanitize=address -g
#TSAN		=	-fsanitize=thread -g
PTHR		=	-pthread

RM		=	rm -f

SRCS		=	main.c \
			check.c \
			init.c \
			time.c \
			monitoring.c \
			philo_action.c \
			run.c \
			de_init.c \
			ft_atoi.c \

OBJS		=	${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${TSAN} ${PTHR} ${OBJS} -o ${NAME}
clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
