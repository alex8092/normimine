/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obs_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/03 00:42:37 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 06:33:33 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_obsp	*ft_push_back_point(t_obsp **begin, int i, t_bsq *bsq)
{
	t_obsp	*current;
	t_obsp	*new;

	current = *begin;
	if (current)
	{
		while (current -> next)
			current = current -> next;
	}
	new = (t_obsp*)malloc(sizeof(t_obsp));
	new -> next = 0;
	new -> x = i % bsq -> line_size;
	new -> y = i / bsq -> line_size;
	new -> square_size = 3;
	new -> value_square = 1;
	new -> square_fill = 0;
	if (current)
		current -> next = new;
	else
		*begin = new;
	return (new);
}

void	ft_change_list_to_array(t_bsq *bsq)
{
	t_obsp	*begin;
	int		i;

	i = 0;
	bsq -> spoints = 0;
	begin = bsq -> points;
	while (begin)
	{
		begin = begin -> next;
		bsq -> spoints++;
	}
	bsq -> apoints = (t_obsp**)malloc(sizeof(t_obsp*) * bsq -> spoints);
	begin = bsq -> points;
	while (begin)
	{
		bsq -> apoints[i] = begin;
		begin = begin -> next;
		i++;
	}
}
