/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:20:59 by chramach          #+#    #+#             */
/*   Updated: 2019/07/19 14:41:23 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int j;

	i = 0;
	while (i < length)
	{
		if (i == length - 1)
		{
			return (tab[i]);
		}
		j = i + 1;
		while (j < length)
		{
			if (tab[i] == tab[j])
			{
				break;
			} 
			if (j == length - 1 && tab[i] != tab[j])
			{
				return (tab[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	int *tab = {2, 7, 3, 4, 3, 2, 4};
	printf("%d\n", ft_unmatch(tab, 7));
	return (0);
}
