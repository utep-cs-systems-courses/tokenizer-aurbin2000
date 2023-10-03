CFLAGS = -g -O3

all: tokenizer

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c

tokenizer: tokenizer.o history.o
	gcc -o tokenizer tokenizer.o history.o

clean:
	rm -f *.o tokenizer
	rm -f *~ tokenizer

run: tokenizer
	./tokenizer

