/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chramach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:21:53 by chramach          #+#    #+#             */
/*   Updated: 2019/07/26 12:28:04 by chramach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (cmpf(item, root->item) < 0 && !root->left)
		root->left = item;
	else if (cmpf(item, root->item) >= 0 && !root->right)
		root->right = item;
	else if (cmpf(item, root->item) < 0)
		btree_insert_data(root->left, item, cmpf);
	else
		btree_insert_data(root->right, item, cmpf);
}
