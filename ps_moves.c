/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:26:49 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 13:33:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_adjust(t_stack *stack, char c)
{
	size_t	i;
	int		tmp;

	i = 0;
	if (c == 'u')
	{
		tmp = stack->tab[0];
		while (i < stack->max - 1)
		{
			stack->tab[i] = stack->tab[i + 1];
			i++;
		}
		stack->tab[i] = tmp;
		return ;
	}
	i = stack->max;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp;
	return ;
}

void	ft_swap(t_stack *stack, char c)
{
	int		tmp;

	if (stack->max <= 1)
		return ;
	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	return ;
}

void	ft_push(t_stack *give, t_stack *take, char c)
{
	if (give->max <= 0)
		return ;
	if (take->max > 0)
		ft_adjust(take, 'd');
	take->tab[0] = give->tab[0];
	ft_adjust(give, 'u');
	take->max = take->max + 1;
	give->max = give->max - 1;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
	return ;
}

void	ft_rotate(t_stack *stack, char c)
{
	int		tmp;
	size_t	i;

	i = 0;
	if (stack->max <= 0)
		return ;
	tmp = stack->tab[0];
	while (i < stack->max - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->max - 1] = tmp;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	return ;
}

void	ft_rev_rotate(t_stack *stack, char c)
{
	int		tmp;
	size_t	i;

	if (stack->max <= 0)
		return ;
	i = stack->max - 1;
	tmp = stack->tab[stack->max - 1];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	return ;
}
