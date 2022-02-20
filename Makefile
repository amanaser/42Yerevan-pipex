SRCS = $(shell find "./functions" -name "*.c") main.c parsing.c pipex.c child_one_two.c
OBJS = ${SRCS:.c=.o}
NAME = pipex
CC   = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re