SRC = main.c history.c tokenizer.c
OBJS = main.o history.o tokenizer.o

CC = gcc
CFLAGS = -g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(OBJS) $(CFLAGS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o tokenizer
	rm -f *~ tokenizer

run: tokenizer
	./tokenizer

