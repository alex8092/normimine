CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = print_alphabet

all: $(EXEC)

$(EXEC): main.o ft_putchar.o ft_print_alphabet.o
	$(CC) -o $(EXEC) $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f main.o
	rm -f ft_puchar.o
	rm -f ft_print_alphabet.o

mrproper: clean
	rm -f $(EXEC)

.PHONY: clean mrproper
