/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:31 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 09:23:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->max <= 1 || stack_b->max <= 1)
		return ;
	ft_swap(stack_a, 'n');
	ft_swap(stack_b, 'n');
	ft_printf("ss\n");
	return ;
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'n');
	ft_rotate(stack_b, 'n');
	ft_printf("rr\n");
	return ;
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rev_rotate(stack_a, 'n');
	ft_rev_rotate(stack_b, 'n');
	ft_printf("rrr\n");
	return ;
}
