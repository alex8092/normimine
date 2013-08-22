CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = bonjour

all: $(EXEC)

$(EXEC): test.o 
	$(CC) -o $(EXEC) $^

test.c: test.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)

.PHONY: clean mrproper
