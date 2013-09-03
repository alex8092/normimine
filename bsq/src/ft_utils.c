/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 17:34:07 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 07:22:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_fill_back_buffer(t_bsq *bsq)
{
	int		i;
	int		j;
	int		size;
	t_obsp	*last;
	t_obsp	*begin;

	if (bsq)
	{
		last = 0;
		begin = 0;
		if (bsq -> buffer)
		{
			size = sizeof(short) * (bsq->len - bsq -> offset - bsq -> nb_line);
			bsq -> back_buffer = (short *)malloc(size);
			i = 0;
			j = bsq -> offset + 1;
			while (bsq -> buffer[j])
			{
				if (bsq -> buffer[j] == bsq -> null_point)
					bsq -> back_buffer[i] = 0;
				else if (bsq -> buffer[j] == bsq -> obs_point)
				{
					bsq -> back_buffer[i] = -1;
					last = ft_push_back_point(&last, i, bsq);
					if (!begin)
						begin = last;
				}
				i++;
				j++;
				if (bsq -> buffer[j] == '\n')
					j++;
			}
			bsq -> points = begin;
		}
	}
}

int		ft_atoi(char *number, int max)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (i < max)
	{
		num *= 10;
		num += (number[i] - '0');
		i++;
	}
	return (num);
}

void	ft_calcul_offset(t_bsq *bsq)
{
	int		i;

	i = 0;
	while (bsq -> buffer[i] >= '0' && bsq -> buffer[i] <= '9')
		i++;
	bsq -> line_size = ft_atoi(bsq -> buffer, i);
	bsq -> null_point = bsq -> buffer[i];
	bsq -> obs_point = bsq -> buffer[i + 1];
	bsq -> reso_point = bsq -> buffer[i + 2];
	bsq -> offset = i + 3;
	bsq -> nb_line = (bsq -> len - bsq -> offset) / (bsq -> line_size + 1);
}

/*
 * TO DELETE !
 */
void	display_back_buffer(t_bsq *bsq)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while ((i+k) < (bsq -> len - bsq -> offset - bsq -> nb_line))
	{
		j = 0;
		while (j < bsq -> line_size)
		{
			if (bsq -> back_buffer[i+j] == -1)
				printf(" \033[34m% 6d\033[0m", bsq -> back_buffer[i+j]);
			else
			{
				if (bsq -> back_buffer[i + j] == bsq -> max)
					printf(" \033[32m% 6d\033[0m", bsq -> back_buffer[i+j]);
				else
					printf(" % 6d", bsq -> back_buffer[i+j]);
			}
			j++;
		}
		i += j;
		k++;
		printf("\n");
	}
}
