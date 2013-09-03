/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 17:52:42 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 09:11:17 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int 	ft_calc(t_bsq *bsq, int x, int y)
{
	return (bsq -> line_size * y + x);
}

void	ft_check_carre(t_bsq *bsq, int x, int y, int value)
{
	if (x >= 1 && x < bsq -> line_size - 1 && y >= 1 && y < bsq -> nb_line - 1)
	{
	if (bsq -> back_buffer[ft_calc(bsq, x - 1, y - 1)] == value
		 && bsq -> back_buffer[ft_calc(bsq, x, y - 1)] == value
		 && bsq -> back_buffer[ft_calc(bsq, x - 1, y)] == value)
	{
		bsq -> back_buffer[ft_calc(bsq, x - 1, y - 1)] = value + 1;
		bsq -> carre = value;
	}
	else if (bsq -> back_buffer[ft_calc(bsq, x - 1, y)] == value
			  && bsq -> back_buffer[ft_calc(bsq, x - 1, y + 1)] == value
			  && bsq -> back_buffer[ft_calc(bsq, x, y + 1)] == value)
	{
		bsq -> back_buffer[ft_calc(bsq, x - 1, y)] = value + 1;
		bsq -> carre = value;
	}
	}
}

int		ft_affect_point(t_bsq *bsq, int x, int y, int value)
{
	int		coord;

	if (!(x >= 0 && x < bsq -> line_size && y >= 0 && y < bsq -> nb_line))
		return (1);
	coord = bsq -> line_size * y + x;
	if (bsq -> onboard == 1)
	{
		if (bsq -> back_buffer[coord] == 0)
		{
			bsq -> back_buffer[coord] = value;
			//if (bsq -> back_buffer[
			return (0);
		}
		else return (1);
	}
	else
	{
		if (bsq -> back_buffer[coord] >= value || bsq -> back_buffer[coord] == 0)
		{
			bsq -> back_buffer[coord] = value;
			//display_back_buffer
			ft_check_carre(bsq, x, y, value);
			return (0);
		}
		else return (1);
	}
}

int		ft_fill_square(t_bsq *bsq, t_obsp *p)
{
	int		i;
	int		offset;
	int		value;
	int		r;

	if (p -> square_fill)
		return (0);
	i = 0;
	r = 0;
	value = p -> value_square;
	while (i < p -> square_size - 1)
	{
		offset = p -> square_size / 2;
		r += ft_affect_point(bsq, p -> x - offset + i, p -> y - offset, value);
		r += ft_affect_point(bsq, p -> x + offset, p -> y - offset + i, value);
		r += ft_affect_point(bsq, p -> x + offset - i, p -> y + offset, value);
	  	r+= ft_affect_point(bsq, p -> x - offset, p -> y + offset - i, value);
		i++;
	}
	if (r == i * 4)
		p -> square_fill = 1;
	else
	{
		p -> value_square += 2;
		p -> square_size += 2;
	}
	return ((p -> square_fill) ? 0 : 1);
}

void	ft_fill_borders(t_bsq *bsq)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		value;
	int		value2;

	w = bsq -> line_size;
	h = bsq -> nb_line;
	value = 1;
	value2 = 1;
	bsq -> onboard = 1;
	while (w > 1 || h > 1)
	{
		x = value - 1;
		y = value - 1;
		while (x < w)
		{
			ft_affect_point(bsq, x, y, value2);
			ft_affect_point(bsq, x, y + h - value, value2);
			x++;
		}
		x--;
		while (y < h)
		{
			ft_affect_point(bsq, x, y, value2);
			ft_affect_point(bsq, x - w + value, y, value2);
			y++;
		}
		w--;
		h--;
		value ++;
		value2 += 2;
	}
}

void	ft_fill_square_final(t_bsq *bsq, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < bsq -> max)
	{
		j = 0;
		while (j < bsq -> max)
		{
			bsq -> back_buffer[ft_calc(bsq, x + j, y + i)] = bsq -> max;
			bsq -> back_buffer[ft_calc(bsq, x + j, y + i)]++;
			j++;
		}
		i++;
	}
	bsq -> max++;
}

void	ft_find_square(t_bsq *bsq)
{
	int		x;
	int		y;

	y = 0;
	while (y < bsq -> nb_line)
	{
		x = 0;
		while (x < bsq -> line_size)
		{
			if (bsq -> back_buffer[ft_calc(bsq, x, y)] == bsq -> max)
			{
				if (bsq -> max % 2 == 0)
				ft_fill_square_final(bsq, x - ((bsq -> max - 1) / 2), y - ((bsq -> max - 1) / 2));
				else
					ft_fill_square_final(bsq, x - (bsq -> max / 2), y - (bsq -> max / 2));
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_begin_back_buffer_parse(t_bsq *bsq)
{
	int		ret;
	int		i;

	ft_fill_borders(bsq);
	bsq -> onboard = 0;
	ret = 1;
	while (ret)
	{
		ret = 0;
		i = 0;
		while (i < bsq -> spoints)
		{
			ret += ft_fill_square(bsq, bsq -> apoints[i]);
			i++;
		}
	}
	i = 0;
	while (i < bsq -> spoints)
	{
		if (bsq -> apoints[i] -> value_square > bsq -> max)
			bsq -> max = bsq -> apoints[i] -> value_square;
		i++;
	}
	bsq -> max -= 2;
	if (bsq -> max == bsq -> carre)
		bsq -> max++;
	ft_find_square(bsq);
	printf("maximum value is : %d\n", bsq -> max);
	printf("carre : %d\n", bsq -> carre);
}

