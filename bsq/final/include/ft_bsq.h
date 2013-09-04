/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/03 23:19:34 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 11:47:46 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>

# define BUFFER_SIZE 1000000

typedef struct s_obs	t_obs;
typedef struct s_bsq	t_bsq;

struct		s_obs
{
	int		x;
	int		y;
	int		square_size;
	int		value_square;
	int		square_fill;
	t_obs	*next;
};

struct		s_bsq
{
	char				null_point;
	char				obs_point;
	char				fill_point;
	int					l_size;
	int					nb_lines;
	int					len;
	int					nb_points;
	t_obs				*points;
	t_obs				*endpoints;
	t_obs				**apoints;
	long int	**buffer;
};

int		ft_natoi(char *str, int n);
void	ft_parse_in_buffer(t_bsq *bsq, char *str, int len);
void	ft_free_ress(t_bsq *bsq);
void	ft_create_buffer(t_bsq *bsq);
void	ft_resolve_map(t_bsq *bsq);
int		ft_affect_point(t_bsq *bsq, int x, int y, long int value);

#endif
