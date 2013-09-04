/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/04 03:25:30 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 06:11:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_display_buffer(t_bsq *bsq)
{
	int		x;
	int		y;

	y = 0;
	while (y < bsq->nb_lines)
	{
		x = 0;
		while (x < bsq->l_size)
		{
			if (bsq->buffer[y][x] != 0)
				printf(" % 6ld", bsq->buffer[y][x]);
			else
				printf(" \033[34m% 6ld\033[0m", bsq->buffer[y][x]);
			++x;
		}
		printf("\n");
		++y;
	}
}

void	ft_fill_borders(t_bsq *bsq, int w, int h, int value)
{
	int		x;
	int		y;

	x = bsq->l_size - w;
	y = bsq->nb_lines - h;
	while (x < w)
	{
		bsq->buffer[y][x] = value;
		bsq->buffer[bsq->nb_lines - 1 - y][x] = value;
		++x;
	}
	while (y < h)
	{
		bsq->buffer[y][x - 1] = value;
		bsq->buffer[y][bsq->l_size - x] = value;
		++y;
	}
	x = (w != (bsq->l_size / 2)) ? w - 1 : w;
	y = (h != (bsq->nb_lines / 2)) ? h - 1 : h;
	if (x != w || y != h)
		ft_fill_borders(bsq, x, y, value + 2);
}

int		ft_fill_square(t_bsq *bsq, t_obs *p)
{
	int		i;
	int		off;
	int		val;
	int		r;

	i = 0;
	r = 0;
	val = p->value_square;
	while (i < p->square_size - 1)
	{
		off = p->square_size / 2;
		r += ft_affect_point(bsq, p->x - off + i, p->y - off, val);
		r += ft_affect_point(bsq, p->x + off, p->y - off + i, val);
		r += ft_affect_point(bsq, p->x + off - i, p->y + off, val);
		r += ft_affect_point(bsq, p->x - off, p->y + off - i, val);
		++i;
	}
	if (r != i * 4)
	{
		p->value_square += 2;
		p->square_size += 2;
	}
	else
		p->square_fill = 1;
	return ((p->square_fill) ? 0 : 1);
}

void	ft_fill_squares(t_bsq *bsq)
{
	int		i;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = 0;
		i = 0;
		while (i < bsq->nb_points)
		{
			if (bsq->apoints[i]->value_square == 1)
				ft_affect_point(bsq, bsq->apoints[i]->x, bsq->apoints[i]->y, 0);
			if (!bsq->apoints[i]->square_fill)
				ret += ft_fill_square(bsq, bsq->apoints[i]);
			++i;
		}
	}
}

void	ft_resolve_map(t_bsq *bsq)
{
	ft_fill_borders(bsq, bsq->l_size, bsq->nb_lines, 1);
	ft_fill_squares(bsq);
	ft_display_buffer(bsq);
}
