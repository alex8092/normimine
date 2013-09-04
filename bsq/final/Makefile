LD = gcc
LDFLAGS = 
INCLUDEDIR = include
SRCDIR = src
OBJDIR = objs
CC = gcc
CFLAGS =  -Wall -Wextra -Werror -O3
LIBS = 
SRC = main.c \
	  ft_util.c \
	  ft_res.c \
	  ft_bsq.c \
	  ft_bsq_calc.c
OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))
NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $(OBJS_PREF) $(LIBS) $(LDFLAGS)

$(OBJS): 
	$(CC) -I$(INCLUDEDIR) -o $(OBJDIR)/$*.o -c $(SRCDIR)/$*.c $(CFLAGS)

clean: 
	/bin/rm -f $(OBJS_PREF)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
