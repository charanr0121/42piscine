/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:10:48 by chramach          #+#    #+#             */
/*   Updated: 2019/07/19 13:41:48 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		hour1;
	int		hour2;
	char	letter1;
	char	letter2;

	if (hour > 24 || hour < 0)
	{
		return ;
	}
	if (hour > 12 && hour != 24)
	{
		hour1 = hour - 12;
		letter1 = 'P';
		hour2 = hour - 11;
		letter2 = 'P';
	} 
	else if (hour == 0 || hour == 24)
	{
		hour1 = 12;
		letter1 = 'A';
		hour2 = 1;
		letter2 = 'A';
	}
	else
	{
		hour1 = hour;
		letter1 = 'A';
		hour2 = hour1 + 1;
		letter2 = 'P';
	}
	if ((hour1 == 11) && letter1 == 'A')
	{
		letter2 = 'P';
	}
	else if (hour1 == 11 && letter1 == 'P')
	{
		letter2 = 'A';
	}
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.\n", hour1, letter1, hour2, letter2);
}

int		main(void)
{
	ft_takes_place(0);
	return (0);
}
