/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_spe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:23:05 by jduval            #+#    #+#             */
/*   Updated: 2022/12/15 07:25:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_find_min(int *tab, size_t max)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = tab[i];
	while (i + 1 < max)
	{
		if (tmp > tab[i + 1] && (i + 1 < max))
			tmp = tab[i + 1];
		i++;
	}
	i = 0;
	while (tmp != tab[i])
		i++;
	return (i);
}
/*
void	ft_algo_three(t_stack *stk, char c)
{
	int	i;

	i = stk->max;
	if (stk->tab[i] > stk->tab[i - 1] && stk->tab[i] < stk->tab[i - 2])
		ft_swap(stk, c);
	else if (stk->tab[i] > stk->tab[i - 1] && stk->tab[i] > stk->tab[i - 2])
	{
		ft_rotate(stk, c);
		if (stk->tab[i] > stk->tab[i - 1] && stk->tab[i] < stk->tab[i - 2])
			ft_swap(stk, c);
	}
	else if (stk->tab[i] < stk->tab[i - 1] && stk->tab[i - 1] > stk->tab[i - 2])
	{
		ft_rev_rotate(stk, c);
		if (stk->tab[i] > stk->tab[i - 1] && stk->tab[i] < stk->tab[i - 2])
			ft_swap(stk, c);
	}
}

void	ft_algo_four(t_stack *stk_a, t_stack *stk_b)
{
	size_t	 i_min;

	i_min = ft_find_min(stk_a->tab, stk_a->max);
	printf("|i_min  = %zu|", i_min);
	if (i_min == 0)
	{
		ft_push(stk_a, stk_b, 'b');
		ft_algo_three(stk_a, 'a');
		ft_push(stk_b, stk_a, 'a');
	}
	else if (i_min == 1)
	{
		ft_swap(stk_a, 'a');
		ft_push(stk_a, stk_b, 'b');
		ft_algo_three(stk_a, 'a');
		ft_push(stk_b, stk_a, 'a');
	} 
	else if (i_min == 2)
	{
		ft_rotate(stk_a, 'a');
		ft_swap(stk_a, 'a');
		ft_push(stk_a, stk_b, 'b');
		ft_algo_three(stk_a, 'a');
		ft_push(stk_b, stk_a, 'a');
	}
	else if (i_min == 3)
	{
		ft_rev_rotate(stk_a, 'a');
		ft_push(stk_a, stk_b, 'b');
		ft_algo_three(stk_a, 'a');
		ft_push(stk_b, stk_a, 'a');
	}
}*/
