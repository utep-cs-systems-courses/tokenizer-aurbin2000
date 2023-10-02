OBJS = tokenizer.o history.o main.o
CFLAGS = -g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(OBJS) $(CFLAGS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenizer
	rm -f *~ tokenizer

run: tokenizer
	./tokenizer

