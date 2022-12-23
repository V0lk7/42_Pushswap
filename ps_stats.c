/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:29:22 by jduval            #+#    #+#             */
/*   Updated: 2022/12/23 16:03:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_is_sorted(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] > tab[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
/*
size_t	ft_find_pos(t_stack *stack, int value, t_bool flag)
{
	size_t	i;
	int		tab[stack->max];
	int		tmp;

	i = 0;
	while (i < stack->max)
	{
		tab[i] = value - stack->tab[i];
		i++;
	}
	tmp = ft_positive_min(tab, stack->max);
	i = ft_negative_max(tab, stack->max);
	if (i < 0)
	{
		if (tmp > 0 && flag == TRUE)
			return (tmp + 1);
		else if (tmp > 0 && flag == FALSE)
			return (stack->max - (tmp + 1));
		else if (tmp == 0 && flag == TRUE)
			return (1);
		else
			return (stack->max);
	}
	else if (tmp < 0)
	{
		if (i > 0 && flag == TRUE)
			return (i + 1);
		else if (i > 0 && flag == FALSE)
			return (stack->max - (i + 1));
		else if (i == 0 && flag == TRUE)
			return (1);
		else
			return (stack->max);
	}
	else
	{
		if (tmp > i * (-1))
		{
			if (i > 0 && flag == TRUE)
				return (i + 1);
			else if (i > 0 && flag == FALSE)
				return (stack->max - (i + 1));
			else if (i == 0 && flag == TRUE)
				return (1);
			else
				return (stack->max);
		}
		else
		{
			if (tmp > 0 && flag == TRUE)
				return (tmp + 1);
			else if (tmp > 0 && flag == FALSE)
				return (stack->max - (tmp + 1));
			else if (tmp == 0 && flag == TRUE)
				return (1);
			else
				return (stack->max);
		}
	}
}*/
/*
size_t	ft_count_sb(size_t len, int index, t_bool flag)
{
	if (flag == TRUE)
		return (index);	
	else 
		return (len - index);
}

size_t	ft_abs(size_t a, size_t b)
{
	size_t	i;

	i = 0;
	if (a > b)
		return ((a - b) + b);
	return ((b - a) + a);	
}

size_t	ft_nbr_move(t_stack *stk_a, t_stack *stk_b, size_t i, t_bool flag)
{
	int		res[4];
	size_t	ra; 
	size_t	rb;
	size_t	rra;
	size_t	index;

	printf("\nnbr count in res for %i\n", stk_b->tab[i]);
	ra = ft_count_sa(stk_a, stk_b->tab[i], TRUE);
	printf("ra = %zu| ", ra);
	rb = ft_count_sb(stk_b->max, i, TRUE);
	printf("rb = %zu| ", rb);
	rra = ft_count_sa(stk_a, stk_b->tab[i], FALSE);
	printf("rra = %zu| ", rra);
	res[0] = ft_abs(ra, rb) + 1;
	res[1] = ft_abs(rra, ft_count_sb(stk_b->max, i, FALSE)) + 1;
	res[2] = ra + ft_count_sb(stk_b->max, i, FALSE) + 1;
	res[3] = rb + rra + 1;
	printf("\nnbr count in res for %i\n", stk_b->tab[i]);
	//for (int i = 0; i < 4; i++)
	//	printf("%i|", res[i]);
	//printf("\n");
	index = ft_find_min(res, 4);
	if (flag == TRUE)
		return (index);
	return (res[index]);
}*/
