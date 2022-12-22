/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:37 by jduval            #+#    #+#             */
/*   Updated: 2022/12/22 15:09:46 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	//for (i = 0; i < 4; i++)
//		printf("%i|", data[i]);
//	printf("\n");
	return (data);
}

void	ft_put_count(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[1] == 0)
	{
		(*data)[2] = ft_count_sa(stk_a, stk_b->tab[(*data)[0]], TRUE);
		(*data)[3] = ft_count_sb(stk_b->max, (*data)[0], TRUE);
	}
	else if((*data)[1] == 1)
	{
		(*data)[2] = ft_count_sa(stk_a, stk_b->tab[(*data)[0]], FALSE);
		(*data)[3] = ft_count_sb(stk_b->max, (*data)[0], FALSE);
	}
	else if ((*data)[1] == 2)
	{
		(*data)[2] = ft_count_sa(stk_a, stk_b->tab[(*data)[0]], TRUE);
		(*data)[3] = ft_count_sb(stk_b->max, (*data)[0], FALSE);
	}
	else if ((*data)[1] == 3)
	{
		(*data)[2] = ft_count_sa(stk_a, stk_b->tab[(*data)[0]], FALSE);
		(*data)[3] = ft_count_sb(stk_b->max, (*data)[0], TRUE);
	}
}

void	ft_algorithm(t_stack *stk_a, t_stack *stk_b)
{
	int		*data;

	while (stk_a->max > 1)
		ft_push(stk_a, stk_b, 'b');
	ft_display(stk_a, stk_a->max, 'a');
	ft_display(stk_b, stk_b->max, 'b');
	while (stk_b->max > 0)
	{
		data = ft_data(stk_a, stk_b);
		while (data[2] > 0 || data[3] > 0)
		{
			if (data[1] == 0)
				ft_pathern0(&data, stk_a, stk_b);
			else if (data[1] == 1)
				ft_pathern1(&data, stk_a, stk_b);
			else if (data[1] == 2)
				ft_pathern2(&data, stk_a, stk_b);
			else if (data[1] == 3)
				ft_pathern3(&data, stk_a, stk_b);
			ft_display(stk_a, stk_a->max, 'a');
			ft_display(stk_b, stk_b->max, 'b');
		}
		ft_push(stk_b, stk_a, 'b');
		free (data);
	}
}
