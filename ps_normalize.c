/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:46:29 by jduval            #+#    #+#             */
/*   Updated: 2022/12/16 14:44:23 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_find_max(int *tab, size_t len)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = i;
	while (i < len)
	{
		if (tab[tmp] < tab[i + 1] && i + 1 <= len)
			tmp = i + 1;
		i++;
	}
	return (tmp);
}

t_stack	*ft_normalize(t_stack *stk_a)
{
	t_stack	*stk_n;
	int		len;
	int		index;

	stk_n = ft_init_stack(stk_a->max, NULL);
	len = stk_a->max - 1;
	while (len >= 0)
	{
		index = ft_find_max(stk_a->tab, stk_a->max - 1);
		stk_a->tab[index] = -2147483648;
		stk_n->tab[index] = len;
		len--;
	}
	stk_n->max = stk_a->max;
	ft_free(NULL, NULL, stk_a);
	return (stk_n);
}
