SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HEAD = ft.h
HEADOBJS = $(HEADER:.h=.h.gch)
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

all: do-op

do-op: OUT
	@${CC} ${CC_FLAGS} -o $@ ${OBJS} ${HEADOBJS}
	@find . -name "*.o" -delete
	@find . -name "*.h.gch" -delete

OUT:
	@${CC} ${CC_FLAGS} -c ${SRCS} ${HEAD}

clean:
	@rm do-op
