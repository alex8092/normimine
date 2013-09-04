/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/04 04:49:42 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 11:47:23 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_affect_point(t_bsq * bsq, int x, int y, long int value)
{
	//printf("x : %d - y : %d - l_size : %d - nb_lines : %d\n", x, y, bsq->l_size, bsq->nb_lines);
	if (!(x >= 0 && x < bsq->l_size && y >= 0 && y < bsq->nb_lines))
		return (1);
	//printf("x : %d - y : %d - l_size : %d - nb_lines : %d\n", x, y, bsq->l_size, bsq->nb_lines);
	if (bsq->buffer[y][x] >= value)
	{
		bsq->buffer[y][x] = value;
		return (0);
	}
	return (1);
}
