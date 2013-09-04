/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/04 01:00:04 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 11:46:17 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_natoi(char *str, int n)
{
	int		number;

	number = 0;
	while (n)
	{
		number *= 10;
		number += (*str - '0');
		n--;
		str++;
	}
	return (number);
}

t_obs	*ft_push_back_obs(t_obs **begin, int x, int y)
{
	t_obs	*new;
	t_obs	*current;

	new = (t_obs*)malloc(sizeof(t_obs));
	current = *begin;
	if (new)
	{
		new->next = 0;
		new->x = x;
		new->y = y;
		new->square_size = 3;
		new->value_square = 1;
		new->square_fill = 0;
		if (current)
		{
			current->next = new;
		}
		else
			*begin = new;
	}
	return (new);
}

void	ft_parse_in_buffer(t_bsq *bsq, char *str, int len)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < len)
	{
		if (str[i] != '\n')
			++bsq->len;
		else
			bsq->l_size = (bsq->l_size != 0) ? bsq->l_size : bsq->len;
		if (str[i] == bsq->obs_point)
		{
			x = (bsq->l_size != 0) ? (bsq->len - 1) % bsq->l_size : bsq->len - 1;
			y = (bsq->l_size != 0) ? (bsq->len - 1) / bsq->l_size : 0;
			bsq->endpoints = ft_push_back_obs(&bsq->endpoints, x, y);
			bsq->nb_points++;
			if (!bsq->points)
				bsq->points = bsq->endpoints;
		}
		++i;
	}
}

void	ft_create_buffer(t_bsq *bsq)
{
	int		y;
	t_obs	*current;
	int		i;

	bsq->buffer = malloc(sizeof(long int*) * bsq->nb_lines);
	if (bsq->buffer)
	{
		y = 0;
		while (y < bsq->nb_lines)
		{
			bsq->buffer[y] = malloc(sizeof(long int) * bsq->l_size);
			++y;
		}
	}
	bsq->apoints = (t_obs**)malloc(sizeof(t_obs*) * bsq->nb_points);
	i = 0;
	current = bsq->points;
	while (current)
	{
		bsq->apoints[i] = current;
		i++;
		current = current -> next;
	}
	printf("i : %d\n", i);
	printf("nb : %d\n", bsq->nb_points);
}
