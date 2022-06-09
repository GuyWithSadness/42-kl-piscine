SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS_DIR = ./srcs
OUT = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
HEAD = ft.h
HEAD_DIR = ./includes
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

all: libft.a

libft.a: OUTPUT

OUTPUT:
	cd ${SRCS_DIR} && \
	${CC} -I${HEAD_DIR} ${CC_FLAGS} -c ${SRCS}
	cd .. \

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -rfv *.a
