/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:13:43 by chramach          #+#    #+#             */
/*   Updated: 2019/07/19 13:54:33 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_rot42(char *str)
{
	int		i;
	int		strlen;
	char	*str2;

	strlen = 0;
	while (str[strlen])
		strlen++;
	str2 = malloc(strlen);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'J') ||
				(str[i] >= 'a' && str[i] <= 'j'))
			str2[i] = str[i] + 16;
		else if ((str[i] > 'J' && str[i] <= 'Z') ||
				(str[i] > 'j' && str[i] <= 'z'))
			str2[i] = str[i] - 10;
		else
			str2[i] = str[i];
		i++;
	}
	return (str2);
}
