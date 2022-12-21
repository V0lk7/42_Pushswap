/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:37 by jduval            #+#    #+#             */
/*   Updated: 2022/12/21 17:11:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_chosen_one(t_stack *stk_a, t_stack *stk_b)
{
	int		results[stk_b->max];
	size_t	i;

	i = 0;
	while (i < stk_b->max)
	{
		results[i] = ft_nbr_move(stk_a, stk_b, i, FALSE);
		i++;
	}
	for (i = 0; i < stk_b->max; i++)
		printf("res[i] = %i\n", results[i]);
	i = ft_find_min(results, stk_b->max);
	printf(" mini = %zu\n", i);
	return (i);
}

void	ft_pathern(t_stack *stk_a, t_stack *stk_b, size_t chosen)
{
	int	count[3];

	if (ft_nbr_move(stk_a, stk_b, chosen, TRUE) == 0)
	{
		
	}
	if (ft_nbr_move(stk_a, stk_b, chosen, TRUE) == 1)
	if (ft_nbr_move(stk_a, stk_b, chosen, TRUE) == 2)
	if (ft_nbr_move(stk_a, stk_b, chosen, TRUE) == 3)
}

void	ft_algorithm(t_stack *stk_a, t_stack *stk_b)
{
	size_t	chosen;
	size_t	pathern;

	while (stk_a->max > 3)
		ft_push(stk_a, stk_b, 'b');
	while (stk_b->max > 0)
	{
		chosen = ft_chosen_one(stk_a, stk_b);
		ft_pathern(stk_a, stk_b, chosen);	
	}
}
