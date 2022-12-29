/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:37 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 09:13:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_order(t_stack *stack)
{
	size_t	i;

	i = ft_find_min(stack->tab, stack->max);
	if (i > (stack->max / 2))
	{
		while (i < stack->max)
		{
			ft_rev_rotate(stack, 'a');
			i++;
		}
		return ;
	}
	while (i > 0)
	{
		ft_rotate(stack, 'a');
		i--;
	}
	return ;
}

static size_t	ft_find_max(int *tab, size_t len)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = i;
	while (i + 1 < len)
	{
		if (tab[tmp] < tab[i + 1] && i + 1 < len)
			tmp = i + 1;
		i++;
	}
	return (tmp);
}

static void	ft_alg_three(t_stack *stk)
{
	size_t	i;

	i = ft_find_max(stk->tab, stk->max);
	if (i == 1)
		ft_rev_rotate(stk, 'a');
	else if (i == 0)
		ft_rotate(stk, 'a');
	if (stk->tab[0] > stk->tab[1])
		ft_swap(stk, 'a');
	return ;
}

static void	ft_dispatch(t_stack *stk_a, t_stack *stk_b)
{
	if (ft_is_sorted(stk_a->tab, stk_a->max) == TRUE)
	{
		ft_free(NULL, NULL, stk_a);
		ft_free(NULL, NULL, stk_b);
		exit (0);
	}
	else if (stk_a->max == 3)
	{
		ft_alg_three(stk_a);
		ft_free(NULL, NULL, stk_a);
		ft_free(NULL, NULL, stk_b);
		exit (0);
	}
	else
		return ;
}

void	ft_algorithm(t_stack *stk_a, t_stack *stk_b)
{
	t_data	data;

	ft_dispatch(stk_a, stk_b);
	while (stk_a->max > 1)
		ft_push(stk_a, stk_b, 'b');
	while (stk_b->max > 0)
	{
		data = ft_data(stk_a, stk_b);
		while (data.move_a > 0 || data.move_b > 0)
		{
			if (data.pathern == 0)
				data = ft_pathern0(data, stk_a, stk_b);
			else if (data.pathern == 1)
				data = ft_pathern1(data, stk_a, stk_b);
			else if (data.pathern == 2)
				data = ft_pathern2(data, stk_a, stk_b);
			else if (data.pathern == 3)
				data = ft_pathern3(data, stk_a, stk_b);
		}
		ft_push(stk_b, stk_a, 'a');
	}
	ft_order(stk_a);
}
