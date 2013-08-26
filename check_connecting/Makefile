CC = g++
CFLAGS = -Wall -Werror -Wextra
LIBS = 
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
