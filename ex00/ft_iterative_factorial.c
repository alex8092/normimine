/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/16 09:28:01 by amerle            #+#    #+#             */
/*   Updated: 2013/08/16 09:50:11 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int factorial;

	if ((nb < 0) || (nb > 12))
		return (0);
	else if (nb == 0)
		return (1);
	factorial = nb;
	nb--;
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}
