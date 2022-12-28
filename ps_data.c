/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:29:22 by jduval            #+#    #+#             */
/*   Updated: 2022/12/28 17:26:00 by jduval           ###   ########.fr       */
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

int	*ft_data(t_stack *stk_a, t_stack *stk_b)
{
	int		results[stk_b->max];
	int		*data;
	size_t	i;

	i = 0;
	data = malloc(sizeof(int) * 4);
	while (i < stk_b->max)
	{
		results[i] = ft_nbr_move(stk_a, stk_b, i, FALSE);
		i++;
	}
	i = ft_find_min(results, stk_b->max);
	data[0] = i;
	data[1] = ft_nbr_move(stk_a, stk_b, i, TRUE);
	ft_put_count(&data, stk_a, stk_b);
	return (data);
}

void	ft_put_count(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[1] == 0)
	{
		(*data)[2] = ft_find_pos(stk_a, stk_b->tab[(*data)[0]], TRUE);
		(*data)[3] = ft_count_stb(stk_b->max, (*data)[0], TRUE);
	}
	else if((*data)[1] == 1)
	{
		(*data)[2] = ft_find_pos(stk_a, stk_b->tab[(*data)[0]], FALSE);
		(*data)[3] = ft_count_stb(stk_b->max, (*data)[0], FALSE);
	}
	else if ((*data)[1] == 2)
	{
		(*data)[2] = ft_find_pos(stk_a, stk_b->tab[(*data)[0]], TRUE);
		(*data)[3] = ft_count_stb(stk_b->max, (*data)[0], FALSE);
	}
	else if ((*data)[1] == 3)
	{
		(*data)[2] = ft_find_pos(stk_a, stk_b->tab[(*data)[0]], FALSE);
		(*data)[3] = ft_count_stb(stk_b->max, (*data)[0], TRUE);
	}
}
