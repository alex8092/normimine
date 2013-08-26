/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/26 18:45:18 by amerle            #+#    #+#             */
/*   Updated: 2013/08/26 18:45:52 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_caller
{
	char c;
	void (*f)(void);
};

typedef struct s_caller t_caller;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	aff_a(void)
{
	ft_putchar('a');
}

void	aff_b(void)
{
	ft_putchar('b');
}

void	aff_c(void)
{
	ft_putchar('c');
}

void	call_func(char c)
{
	t_caller table[] =
	{
		{'a', aff_a},
		{'b', aff_b},
		{'c', aff_c},
		{0, 0}
	};
	t_caller *tmp;

	tmp = table;
	while (tmp -> c)
	{
		if (tmp -> c == c)
		{
			tmp -> f();
			break ;
		}
		tmp++;
	}
}


int		main(void)
{
	call_func('a');
	call_func('z');
	call_func('b');
	call_func('c');
	return (0);
}
