/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/14 13:44:37 by amerle            #+#    #+#             */
/*   Updated: 2013/08/14 18:19:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	counter;

	counter = 'a';
	while(counter <= 'z')
	{
		ft_putchar(counter);
		counter++;
	}
}
