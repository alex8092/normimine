/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/25 00:57:08 by amerle            #+#    #+#             */
/*   Updated: 2013/08/25 01:36:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int		main(void)
{
	std::string s("amerle");
	std::string l("xnielnsa");
	for (int i = 0; i < 42;i++)
	{
		for (int j = 0; j < s.size();j++)
		{
			int i = s[j];
			i += 16;
			if (i > 128)
				i -= 127;
			s[j] = i;
		}
		cout << s << endl;
	}

	return 0;
}
