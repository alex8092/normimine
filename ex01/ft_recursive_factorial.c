/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/16 09:53:42 by amerle            #+#    #+#             */
/*   Updated: 2013/08/16 09:58:41 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if ((nb < 0) || (nb > 12))
		return (0);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
