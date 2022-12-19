/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:29:22 by jduval            #+#    #+#             */
/*   Updated: 2022/12/19 16:05:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_is_sorted(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

size_t	ft_count_nbr(int *tab, size_t len, int nbr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab[i] != nbr)
		i++;
	if (i < len / 2)
		return (i + 1);
	while (i + j <= len)
		j++;
	return (j + 1);
}

size_t	ft_count_position(int *tab, size_t len, int nbr)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (len == 0)
		return (0);
	while (nbr > tab[i])
		i++;
	if (i < len / 2)
		return (i);
	while (i + j <= len)
		j++;
	return (j);
}
/*
void	ft_which_move(t_stack *stk_a, t_stack *stk_b)
{
	int		count_nbr;
	int		position;
	size_t	max_index;

	max_index = ft_find_max(stk_b->tab, stk_b->max);
	count_nbr = ft_count_nbr(stk_b->tab, stk_b->max, stk_b->tab[max_index]);
	position = (stk_a->tab, stk_a->max, stk_b->tab[max_index]);
	if (count_nbr <= stk_b->max / 2 && position <= stk_a->max / 2)
	{
		ft_rotate()
	}	
		
}*/
