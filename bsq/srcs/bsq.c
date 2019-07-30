/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:55:43 by chramach          #+#    #+#             */
/*   Updated: 2019/07/26 15:56:55 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_bsq.h"

int		size(char **og)
{
	int i;
	int j;
	int size;

	i = 0;
	size = 0;
	while (og[i])
	{
		j = 0;
		while (og[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

void	init(char **og, int len)
{
	int i;
	int j;
	int **num;

	num = (int **)malloc(sizeof(int) * 500);
	i = 0;
	while (og[i])
	{
		num[i] = (int *)malloc(sizeof(int) * 500);
		j = 0;
		while (og[i][j])
		{
			if (og[i][j] == '.')
				num[i][j] = 1;
			else
				num[i][j] = 0;
			j++;
		}
		i++;
	}
	solve(num, len, og);
}

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}

void	solve(int **num, int len, char **og)
{
	int i;
	int j;
	int max;

	i = 1;
	max = 0;
	while (num[i])
	{
		j = 1;
		while (j < len)
		{
			if (num[i][j] > 0)
				num[i][j] = min(num[i - 1][j], num[i - 1][j - 1],
					num[i][j - 1]) + 1;
			if (num[i][j] > max)
				max = num[i][j];
			j++;
		}
		i++;
	}
	convert(num, og, len, max);
}

void	convert(int **num, char **og, int len, int max)
{
	int i;
	int j;
	int k;
	int j_res;
	int i_res;

	i = 0;
	i_res = -1;
	j_res = -1;
	while (num[i] && j_res == -1 && i_res == -1)
	{
		j = 0;
		while (j < len)
		{
			if (num[i][j] == max)
			{
				i_res = i;
				j_res = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < max)
	{
		j = j_res;
		k = 0;
		while (k < max)
		{
			og[i_res][j] = 'x';
			j--;
			k++;
		}
		i_res--;
		i++;
	}
	display(og, len);
}

void	display(char **og, int len)
{
	int i;
	int j;

	i = 0;
	while (og[i])
	{
		j = 0;
		while (j < len)
		{
			ft_putchar(og[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*char    **map(char *file, int collen)
{
    int fd;
    int ret;
    int rowlen;
    char *buf;
    int i;
    int j;    
    i = 0;
    j = 0;
    if (open(file, O_RDONLY) < 0)
        write(1, "map error\n", 9);
    fd = open(file, O_RDONLY);
    while (read(fd, buf , 1) > 0)
        buf[ret] = '\0';
    rowlen = get_rowlen(buf);
    while (i < rowlen)
    {
        new[i][j] = buf[i][j];
        i++;
        while(j < collen
    }
    return (buf);
}*/

void	map(char *file)
{
	char **og;
	char c;
	int fd;
	int i;
	int j;
	int col_num;
	int row_num;
	int first_new_line;

	col_num = -1;
	if (open(file, O_RDONLY) < 0)
	{
		ft_putstr("map error\n");
	}
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c =='\n')	
			col_num++;
	first_new_line = 0;
	row_num = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n' && first_new_line == 0)
			first_new_line = 1;
		if (first_new_line == 1 && c != '\n')
			row_num++;
		if (c == '\n' && first_new_line == 1)
			break ;
	}

	og = (char **)malloc(sizeof(char) * col_num);
	i = -1;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			i++;
			og[i] = (char *)malloc(sizeof(char) * row_num);
			j = 0;	
		}
		else if (i >= 0 && c != '\n')
		{
			og[i][j] = c;
			j++;
		}
		printf("%c",c);
	}
	close(fd);
	init(og, row_num);
}

// int		main(int ac, char **av)
// {
// 	char	**new;
// 	int		i;
// 	int		j;
// 	int		len;

// 	new = (char **)malloc(sizeof(char) * 9);
// 	len = 0;
// 	while (av[1][len])
// 		len++;
// 	i = 0;
// 	while (av[i + 1])
// 	{
// 		new[i] = (char *)malloc(sizeof(char) * len * 500);
// 		j = 0;
// 		while (av[i + 1][j])
// 		{
// 			new[i][j] = av[i + 1][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (ac > 1)
// 		init(new, len);
// 	ft_putchar('\n');
// 	return (0);
// }

int		main(int ac, char **av)
{
	//char	**new;
	int		i;
	//int		j;
	//int		len;

	i = 1;
	if (ac <= 1)
	{
		ft_putchar('\n');
	}
	else
	{
		while (i < ac)
		{
			map(av[i]);
		}
	}

	ft_putchar('\n');
	return (0);
}
