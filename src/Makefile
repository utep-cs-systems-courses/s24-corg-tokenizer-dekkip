
OBJS= tokenizer.o uimain.o history.o tester.o

CFLAGS=-g -03

all: tokens

tokens: $(OBJS)
	cc -o tokens $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokens

run:tokens
	./tokens
