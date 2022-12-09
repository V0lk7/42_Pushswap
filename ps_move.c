/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:26:49 by jduval            #+#    #+#             */
/*   Updated: 2022/12/09 17:29:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;
	if (stack->max <= 1)
		return ;
	tmp = stack->tab[stack->max - 1];
	stack->tab[stack->max - 1] = stack->tab[stack->max - 2];
	stack->tab[stack->max - 2] = tmp;
}

void	ft_push(t_stack *give, t_stack *take)
{
	if (give->max <= 0)
		return ;
	take->tab[take->max] = give->tab[give->max - 1];
	give->max--;
	take->max++;
}

void	ft_rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->tab[stack->max - 1];
	i = stack->max - 1;
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp;
}

void	ft_rev_rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	i = 0;
	tmp = stack->tab[0];
	while(i < stack->max - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
}
