SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS_DIR = ./srcs
OUT = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
HEAD = ft.h
HEAD_DIR = ./includes
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

.PHONY : all

re: fclean all

all: libft.a clean

libft.a: OUTPUT
	ar -rcs $@ ${OUT}

OUTPUT:
	cd ${SRCS_DIR} && \
	${CC} -I${HEAD_DIR} ${CC_FLAGS} -c ${SRCS}
	cd ..

clean:
	find . -name "*.o" -delete

fclean:
	find . -name "*.o" -delete
	rm -rf *.a
