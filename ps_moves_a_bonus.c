/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_a_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:26:49 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 16:54:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_sa(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;

	if (stack_a->max <= 1)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
	tmp = stack_b->tab[0];
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->max <= 0)
		return ;
	if (stack_a->max > 0)
		ft_adjust_filled(stack_a);
	stack_a->tab[0] = stack_b->tab[0];
	ft_adjust(stack_b);
	stack_a->max = stack_a->max + 1;
	stack_b->max = stack_b->max - 1;
}

void	ft_ra(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	size_t	i;

	i = 0;
	if (stack_a->max <= 0)
		return ;
	tmp = stack_a->tab[0];
	while (i < stack_a->max - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[stack_a->max - 1] = tmp;
	i = stack_b->max;
}

void	ft_rra(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	size_t	i;

	if (stack_a->max <= 0)
		return ;
	i = stack_a->max - 1;
	tmp = stack_a->tab[stack_a->max - 1];
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = tmp;
	i = stack_b->max;
}
