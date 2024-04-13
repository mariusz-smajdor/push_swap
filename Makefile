NAME =		push_swap
CC =		cc
FLAGS =		-Wall -Wextra -Werror
RM =		rm -f

SRCS =		$(wildcard *.c) \
			$(wildcard */*.c) \
			$(wildcard */*/*.c) \
			${wildcard */*/*/*.c}

OBJS	= $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}
	${MAKE} clean

clean:
	${RM} *.o */*.o */*/*.o */*/*/*.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
