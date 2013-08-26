/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/24 14:19:13 by amerle            #+#    #+#             */
/*   Updated: 2013/08/25 00:00:23 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stdio.h>
#include <sys/types.h>

int		main(void)
{
	int p[2];
	pid_t id;
	char receives[2000];
	char * args[2];

	pipe(p);

	id = fork();
	if (id == 0)
	{
		args[0] = (char *)"-a";
		args[1] = 0;
		close(p[0]);
		execv("/usr/bin/w", args);
	}
	else
	{
		close(p[1]);
		read(p[0], receives, 2000);
		std::string s = receives;
		std::cout << s << std::endl;
	}

	return 0;
}
