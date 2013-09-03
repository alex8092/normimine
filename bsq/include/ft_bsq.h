/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 14:13:03 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 07:09:22 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct s_bsq	t_bsq;

typedef struct s_obs_point t_obsp;

struct s_obs_point
{
	int		x;
	int		y;
	int		square_size;
	int		value_square;
	int		square_fill;
	t_obsp	*next;
};

struct s_bsq
{
	char	*buffer;
	short	*back_buffer;
	int		len;
	int		offset;
	int		line_size;
	int		nb_line;
	char	null_point;
	char	obs_point;
	char	reso_point;
	int		max;
	t_obsp	*points;
	t_obsp	**apoints;
	int		spoints;
	int		onboard;
	int		carre;
	int		x_find;
	int		y_find;
};

typedef struct s_bb_fill t_bb_fill;

struct	s_bb_fill
{
	int		x;
	int		y;
	int		value;
	void	(*applyf)(int *, int *);
};

void	ft_release_ressources(t_bsq *bsq);
void	ft_fill_back_buffer(t_bsq *bsq);
void	ft_calcul_offset(t_bsq *bsq);
void	ft_begin_back_buffer_parse(t_bsq *bsq);
t_obsp	*ft_push_back_point(t_obsp **points, int i, t_bsq *bsq);
void	ft_change_list_to_array(t_bsq *bsq);
void	display_back_buffer(t_bsq *bsq); // TO DELETE

#endif
