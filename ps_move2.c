/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:31 by jduval            #+#    #+#             */
/*   Updated: 2022/12/12 15:36:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (stack_b->max <= 1 || stack_b->max <= 1)
		return ;
	tmp = stack_a->tab[stack_a->max - 1];
	stack_a->tab[stack_a->max - 1] = stack_a->tab[stack_a->max - 2];
	stack_a->tab[stack_a->max - 2] = tmp;
	tmp = stack_b->tab[stack_b->max - 1];
	stack_b->tab[stack_b->max - 1] = stack_b->tab[stack_b->max - 2];
	stack_b->tab[stack_b->max - 2] = tmp;
	ft_printf("ss\n");
	return ;
}

void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	
}
