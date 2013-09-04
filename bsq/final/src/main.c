/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/03 23:20:06 by amerle            #+#    #+#             */
/*   Updated: 2013/09/04 08:57:40 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_display_error()
{
	
}

void	ft_read(t_bsq *bsq, int fd)
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	char	first_line;
	int		i;

	(void)bsq;
	first_line = 1;
	i = 0;
	while((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		if (first_line)
		{
			while (buffer[i] >= '0' && buffer[i] <= '9')
				i++;
			bsq->nb_lines = ft_natoi(buffer, i);
			bsq->null_point = buffer[i];
			bsq->obs_point = buffer[i + 1];
			bsq->fill_point = buffer[i + 2];
			i += 3;
			first_line = 0;	
		}
		ft_parse_in_buffer(bsq, buffer + i, ret - i);
	}
}

int		ft_open(char *file)
{
	int		fd;

	fd = 0;
	if (file != 0)
	{
		fd = open(file, O_RDONLY);
	}
	return (fd);
}

void	ft_start_bsq(char *file)
{
	int		fd;
	t_bsq	bsq;

	fd = ft_open(file);
	if (fd != -1)
	{
		bsq.len = 0;
		bsq.l_size = 0;
		bsq.points = 0;
		bsq.endpoints = 0;
		bsq.nb_points = 0;
		ft_read(&bsq, fd);
		ft_create_buffer(&bsq);
		ft_resolve_map(&bsq);
		printf("line size : %d\n", bsq.l_size);
		printf("null point : %c\n", bsq.null_point);
		printf("obs point : %c\n", bsq.obs_point);
		printf("fill point : %c\n", bsq.fill_point);
		printf("len : %d\n", bsq.len);
		printf("nb lines : %d\n", bsq.nb_lines);
	}
	else
		ft_display_error();
	ft_free_ress(&bsq);
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
	{
		ft_start_bsq(0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_start_bsq(argv[i]);
			i++;
		}
	}
	return (0);
}
