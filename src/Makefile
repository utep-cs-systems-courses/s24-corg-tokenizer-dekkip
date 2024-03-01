
OBJS= tokenizer.o uimain.o history.o

CFLAGS=-g -O3

all: tokens

tokens: $(OBJS)
	cc -o tokens $(CFLAGS) $(OBJS)

tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

clean:
	rm -f *.o tokens

run:tokens
	./tokens
