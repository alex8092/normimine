/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeressources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 16:28:04 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 03:53:31 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_release_ressources(t_bsq *bsq)
{
	t_obsp *begin;
	
	begin = bsq -> points;
	while (begin)
	{
		bsq -> points = begin -> next;
		free(begin);
		begin = bsq -> points;
	}
	if (bsq)
	{
		if (bsq -> buffer)
			free(bsq -> buffer);
		if (bsq -> back_buffer)
			free(bsq -> back_buffer);
		free(bsq -> apoints);
		free(bsq);
	}
}
