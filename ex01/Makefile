CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = ft_recursive_factorial

all: $(EXEC)

$(EXEC): main.o ft_putchar.o $(EXEC).o
	$(CC) -o $(EXEC) $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f main.o
	rm -f ft_puchar.o
	rm -f $(EXEC).o

mrproper: clean
	rm -f $(EXEC)

.PHONY: clean mrproper
