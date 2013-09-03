/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/02 14:02:09 by amerle            #+#    #+#             */
/*   Updated: 2013/09/03 08:47:19 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_display_error()
{
	// print errors
	return (-1);
}

void	ft_memcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned long int	*dest_opti;
	unsigned long int	*src_opti;

	dest_opti = (unsigned long int*)dest;
	src_opti = (unsigned long int*)src;
	i = 0;
	while (i < (size / sizeof(unsigned long int)))
	{
		dest_opti[i] = src_opti[i];
		i++;
	}
	i *= sizeof(unsigned long int);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

t_bsq	*ft_read(int fd, t_bsq *bsq)
{
	int		ret;
	char	buffer[4096];
	char	*tmp;

	ret = 0;
	tmp = 0;
	while ((ret = read(fd, buffer, 4096)) > 0)
	{
		tmp = (char*)malloc(sizeof(char) * (bsq -> len + ret + 1));
		if (bsq -> buffer)
			ft_memcpy(tmp, bsq -> buffer, bsq -> len);
		ft_memcpy(tmp + bsq -> len, buffer, ret);
		tmp[bsq -> len + ret] = 0;
		if (bsq -> buffer)
			free(bsq -> buffer);
		bsq -> len += ret;
		bsq -> buffer = tmp;
	}
	if (ret == -1)
	{
		ft_display_error();
		return (0);
	}
	else
		return (bsq);
}

t_bsq	*ft_open(char *file)
{
	int		fd;
	t_bsq	*bsq;

	bsq = (t_bsq *)malloc(sizeof(t_bsq));
	bsq -> buffer = 0;
	bsq -> len = 0;
	bsq -> offset = 0;
	bsq -> back_buffer = 0;
	bsq -> points = 0;
	bsq -> max = 0;
	fd = 0;
	if (file != 0)
	{
		fd = open(file, O_RDONLY);
	}
	if (fd == -1)
	{
		ft_display_error();
		return (0);
	}
	return (ft_read(fd, bsq));
}

int		main(int argc, char **argv)
{
	t_bsq	*bsq;
	int		i;

	i = 1;
	if (argc == 1)
	{
		bsq = ft_open(0);
		//if (bsq)
	//		if (bsq -> buffer)
	//	
		ft_calcul_offset(bsq);
			printf("line size : %d\n", bsq -> line_size);
			printf("null point : %c\n", bsq -> null_point);
			printf("obs point : %c\n", bsq -> obs_point);
			printf("reso point : %c\n", bsq -> reso_point);
			printf("nb line : %d\n", bsq -> nb_line);
			ft_fill_back_buffer(bsq);
			ft_change_list_to_array(bsq);
		ft_begin_back_buffer_parse(bsq);
		ft_release_ressources(bsq);
	}
	else
	{
		while (i < argc)
		{
			bsq = ft_open(argv[i]);
			//if (bsq)
			//	if (bsq -> buffer)
		//			printf("%s\n", bsq -> buffer);
			ft_calcul_offset(bsq);
			printf("line size : %d\n", bsq -> line_size);
			printf("null point : %c\n", bsq -> null_point);
			printf("obs point : %c\n", bsq -> obs_point);
			printf("reso point : %c\n", bsq -> reso_point);
			printf("nb line : %d\n", bsq -> nb_line);
			ft_fill_back_buffer(bsq);
			ft_change_list_to_array(bsq);
			ft_begin_back_buffer_parse(bsq);
		//	display_back_buffer(bsq);
		//	printf("max : %d\n", bsq -> max);
			ft_release_ressources(bsq);
			i++;
		}
	}
	return (0);
}
