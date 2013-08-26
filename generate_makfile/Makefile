CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -L../ex00/ -lft
EXEC = prog

all: $(EXEC)

$(EXEC): main.o 
	$(CC) -o $(EXEC) $^ $(LIBS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)

.PHONY: clean mrproper
