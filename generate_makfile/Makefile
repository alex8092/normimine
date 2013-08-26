LD = gcc
LDFLAGS = 
INCLUDEDIR = .
SRCDIR = .
OBJDIR = .
CC = gcc
CFLAGS =  -Wall -Wextra -Werror 
LIBS = 
EXEC = prog

all: $(EXEC)

$(EXEC): 
	$(LD) -o $(EXEC) $^ $(LIBS) $(LDFLAGS)

clean: 
fclean: clean
	/bin/rm -f $(EXEC)

re: fclean all

.PHONY: clean fclean re all
