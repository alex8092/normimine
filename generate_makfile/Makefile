LD = gcc
LDFLAGS = 
INCLUDEDIR = .
SRCDIR = .
OBJDIR = .
CC = gcc
CFLAGS =  -Wall -Wextra -Werror 
LIBS = 
SRC = Makefile.c \
	genmake.c \
	genmakepp.c \
	main.cpp.c \
	mainpp.cpp.c
OBJS = $(SRC:.c=.o)
NAME = prog

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $^ $(LIBS) $(LDFLAGS)

$(OBJS): 
	$(CC) -I$(INCLUDEDIR) -o $(OBJDIR)/$*.o -c $(SRCDIR)/$*.c $(CFLAGS)

clean: 
	/bin/rm -f $(OBJDIR)/Makefile.o
	/bin/rm -f $(OBJDIR)/genmake.o
	/bin/rm -f $(OBJDIR)/genmakepp.o
	/bin/rm -f $(OBJDIR)/main.cpp.o
	/bin/rm -f $(OBJDIR)/mainpp.cpp.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
