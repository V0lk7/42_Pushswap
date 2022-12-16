/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:37 by jduval            #+#    #+#             */
/*   Updated: 2022/12/16 13:27:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_algorithm(t_stack *stk_a, t_stack *stk_b)
{
	size_t	index;
	t_bool	flag;

	index = 0;
	flag = ft_is_sorted(stk_a->tab, stk_a->max);	
	while (flag == FALSE)
	{
		index = ft_find_min(stk_a->tab, stk_a->max);
		flag = ft_is_sorted(stk_a->tab, stk_a->max);
		if (flag == 0 && stk_a->max == 2)
			ft_swap(stk_a, 'a');
		if (index >= stk_a->max / 2 && flag == 0)
		{
			while (index != 0)
			{
				ft_rev_rotate(stk_a, 'a');
				index = ft_find_min(stk_a->tab, stk_a->max);
			}
			ft_push(stk_a, stk_b, 'b');
		}
		else if (index < stk_a->max / 2 && flag == 0)
		{
			while (index != 0)
			{
				ft_rotate(stk_a, 'a');
				index = ft_find_min(stk_a->tab, stk_a->max);
			}
			ft_push(stk_a, stk_b, 'b');
		}
		flag = ft_is_sorted(stk_a->tab, stk_a->max);
	}
	ft_display(stk_a, stk_a->max, 'a');
	while (stk_b->max > 0)
		ft_push(stk_b, stk_a, 'a');
}
