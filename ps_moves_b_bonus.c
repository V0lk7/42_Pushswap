/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_b_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:57:32 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 16:55:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_sb(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;

	if (stack_b->max <= 1)
		return ;
	tmp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tmp;
	tmp = stack_a->tab[0];
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->max <= 0)
		return ;
	if (stack_b->max > 0)
		ft_adjust_filled(stack_b);
	stack_b->tab[0] = stack_a->tab[0];
	ft_adjust(stack_a);
	stack_b->max = stack_b->max + 1;
	stack_a->max = stack_a->max - 1;
}

void	ft_rb(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	size_t	i;

	i = 0;
	if (stack_b->max <= 0)
		return ;
	tmp = stack_b->tab[0];
	while (i < stack_b->max - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[stack_b->max - 1] = tmp;
	i = stack_a->max;
}

void	ft_rrb(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	size_t	i;

	if (stack_b->max <= 0)
		return ;
	i = stack_b->max - 1;
	tmp = stack_b->tab[stack_b->max - 1];
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = tmp;
	i = stack_a->max;
}
