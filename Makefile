NAME =			push_swap
CC =			cc
FLAGS =			-Wall -Wextra -Werror
RM =			rm -f
MAKEFLAGS +=	-s

SRCS =			app/push_swap/push_swap.c app/push_swap/process_input.c app/push_swap/init_stack.c \
				app/push_swap/sort_stack/sort_stack.c app/push_swap/sort_stack/sort_stack_utils.c \
				app/push_swap/sort_stack/rotate_stacks.c app/push_swap/sort_stack/calculate_rotations.c \
				app/push_swap/sort_stack/calculate_rotation_a.c app/push_swap/sort_stack/calculate_rotation_b.c \
				app/push_swap/sort_stack/operations/swap.c app/push_swap/sort_stack/operations/push.c \
				app/push_swap/sort_stack/operations/rotate.c app/push_swap/sort_stack/operations/reverse_rotate.c \

BONUS =			app/checker/checker.c app/push_swap/process_input.c app/push_swap/init_stack.c \
				app/push_swap/sort_stack/sort_stack_utils.c app/push_swap/sort_stack/operations/swap.c \
				app/push_swap/sort_stack/operations/push.c app/push_swap/sort_stack/operations/rotate.c \
				app/push_swap/sort_stack/operations/reverse_rotate.c

UTILS =			utils/ft_printf/ft_printf.c utils/ft_printf/format_specifiers/print_char.c \
				utils/ft_printf/format_specifiers/print_hex.c utils/ft_printf/format_specifiers/print_number.c \
				utils/ft_printf/format_specifiers/print_pointer.c utils/ft_printf/format_specifiers/print_string.c \
				utils/ft_printf/format_specifiers/print_unsigned_number.c utils/ft_arrfree.c utils/ft_atoi.c \
				utils/ft_error.c utils/ft_get_next_line.c utils/ft_isdigit.c utils/ft_issign.c utils/ft_lstadd_back.c \
				utils/ft_lstfree.c utils/ft_lstlast.c utils/ft_lstmax.c utils/ft_lstmin.c utils/ft_lstnew.c utils/ft_lstsize.c \
				utils/ft_memcpy.c utils/ft_split.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlcpy.c \
				utils/ft_strlen.c utils/ft_strncmp.c utils/ft_substr.c

OBJS =			${SRCS:.c=.o}
BONUS_OBJS =	${BONUS:.c=.o}
UTILS_OBJS =	${UTILS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${UTILS_OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${UTILS_OBJS}
	${MAKE} clean

bonus: ${UTILS_OBJS} ${BONUS_OBJS}
	${CC} ${FLAGS} -o checker ${BONUS_OBJS} ${UTILS_OBJS}
	${MAKE} clean

clean:
	${RM} ${OBJS} ${BONUS_OBJS} ${UTILS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
