/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/04 02:03:27 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 05:11:24 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_free_ress(t_bsq *bsq)
{
	t_obs	*current;
	int		y;

	current = bsq->points;
	while (current)
	{
		bsq->points = current -> next;
		free(current);
		current = bsq->points;
	}
	if (bsq->buffer)
	{
		y = 0;
		while (y < bsq->nb_lines)
		{
			free(bsq->buffer[y]);
			++y;
		}
		free(bsq->buffer);
	}
	if (bsq->apoints)
		free(bsq->apoints);
}
