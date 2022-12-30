/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:31 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 16:55:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_adjust(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->max - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
}

void	ft_adjust_filled(t_stack *stack)
{
	size_t	i;

	i = stack->max;
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
}	

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a, stack_b);
	ft_sb(stack_a, stack_b);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a, stack_b);
	ft_rb(stack_a, stack_b);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a, stack_b);
	ft_rrb(stack_a, stack_b);
}
