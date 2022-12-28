/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stat_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:22:09 by jduval            #+#    #+#             */
/*   Updated: 2022/12/28 15:49:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_count_sta(t_stack *stack, size_t i, int value, t_bool flag)
{
	int	tmp;

	tmp = value - stack->tab[i];
	if (flag == TRUE && ((i == 0 && tmp < 0) || (i == 0 && stack->max == 1)))
		return (i);
	else if (flag == TRUE && i == 0 && tmp > 0)
		return (1);
	else if (flag == TRUE && i > 0 && tmp < 0)
		return (i);
	else if (flag == TRUE)
		return (i + 1);
	if (flag == FALSE && i == 0 && tmp > 0)
		return (stack->max - 1);
	else if (flag == FALSE && i == 0 && tmp < 0)
		return (i);
	else if (flag == FALSE && i > 0 && tmp > 0)
		return (stack->max - (i + 1));
	else 
		return (stack->max - i);
}

size_t	ft_count_stb(size_t len, int index, t_bool flag)
{
	if (index == 0)
		return (0);
	if (flag == TRUE)
		return (index);	
	else 
		return (len - index);
}

size_t	ft_find_pos(t_stack *stack, int value, t_bool flag)
{
	size_t	i;
	size_t	j;
	int	tmp;
		
	i = 0;
	j = 0;
	tmp = ft_abs(value - stack->tab[i]);
	while (i < stack->max)
	{
		if (ft_abs(value - stack->tab[i]) < tmp)
		{	
			tmp = ft_abs(value - stack->tab[i]);
			j = i;
		}
		i++;
	}
	j = ft_count_sta(stack, j, value, flag);
	return (j);
}

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

size_t	ft_merge(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}
