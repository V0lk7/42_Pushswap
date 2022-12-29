/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:29:22 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 09:21:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_is_sorted(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

size_t	ft_find_min(int *tab, size_t len)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = i;
	if (len <= 0)
		return (0);
	while (i < len - 1)
	{
		if (tab[tmp] > tab[i + 1])
			tmp = i + 1;
		i++;
	}
	return (tmp);
}

size_t	ft_nbr_move(t_stack *stk_a, t_stack *stk_b, size_t i, t_bool flag)
{
	int		res[5];
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;

	ra = ft_find_pos(stk_a, stk_b->tab[i], TRUE);
	rb = ft_count_stb(stk_b->max, i, TRUE);
	rra = ft_find_pos(stk_a, stk_b->tab[i], FALSE);
	rrb = ft_count_stb(stk_b->max, i, FALSE);
	res[0] = ft_merge(ra, rb);
	res[1] = ft_merge(rra, rrb);
	res[2] = ra + rrb;
	res[3] = rb + rra;
	res[4] = ft_find_min(res, 4);
	if (flag == TRUE)
		return (res[4]);
	return (res[res[4]]);
}

t_data	ft_data(t_stack *stk_a, t_stack *stk_b)
{
	t_data	data;
	int		*results;
	size_t	i;

	i = 0;
	results = malloc(sizeof(int) * stk_b->max);
	if (results == NULL)
	{
		ft_free(NULL, NULL, stk_a);
		ft_free(NULL, NULL, stk_b);
		exit (0);
	}
	while (i < stk_b->max)
	{
		results[i] = ft_nbr_move(stk_a, stk_b, i, FALSE);
		i++;
	}
	i = ft_find_min(results, stk_b->max);
	free(results);
	data.index = i;
	data.pathern = ft_nbr_move(stk_a, stk_b, i, TRUE);
	data = ft_put_count(data, stk_a, stk_b);
	return (data);
}

t_data	ft_put_count(t_data data, t_stack *stk_a, t_stack *stk_b)
{
	if (data.pathern == 0)
	{
		data.move_a = ft_find_pos(stk_a, stk_b->tab[data.index], TRUE);
		data.move_b = ft_count_stb(stk_b->max, data.index, TRUE);
	}
	else if (data.pathern == 1)
	{
		data.move_a = ft_find_pos(stk_a, stk_b->tab[data.index], FALSE);
		data.move_b = ft_count_stb(stk_b->max, data.index, FALSE);
	}
	else if (data.pathern == 2)
	{
		data.move_a = ft_find_pos(stk_a, stk_b->tab[data.index], TRUE);
		data.move_b = ft_count_stb(stk_b->max, data.index, FALSE);
	}
	else if (data.pathern == 3)
	{
		data.move_a = ft_find_pos(stk_a, stk_b->tab[data.index], FALSE);
		data.move_b = ft_count_stb(stk_b->max, data.index, TRUE);
	}
	return (data);
}
