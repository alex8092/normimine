/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/16 10:02:27 by amerle            #+#    #+#             */
/*   Updated: 2013/08/16 11:21:39 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	power_result;
	int	index;

	index = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	power_result = nb;
	while (index < power)
	{
		power_result *= nb;
		index++;
	}
	return (power_result);
}
