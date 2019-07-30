/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:44:40 by chramach          #+#    #+#             */
/*   Updated: 2019/07/29 10:44:42 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

void	ft_putchar(char c);

void	ft_putnbr(int nb);

void	ft_putstr(char *str);

void solve(int **num, int len, char **og);

void convert(int **num, char **og, int len, int max);

void	display(char **og, int len);

#endif