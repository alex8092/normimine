#ifndef FT_STRING_H
# define FT_STRING_H

struct	st_string
{
	char	*str;
	int	length;
};

typedef struct st_string t_string;

int	ft_setstr(char *str);

char 	*ft_substr(int start, int length);

#endif
