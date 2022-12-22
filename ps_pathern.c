/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pathern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:57:41 by jduval            #+#    #+#             */
/*   Updated: 2022/12/22 14:11:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pathern0(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[2] > 0 && (*data)[3] > 0)
	{
		ft_rr(stk_a, stk_b);
		(*data)[2]--;
		(*data)[3]--;
	}
	else if ((*data)[2] > 0 && (*data)[3] == 0)
	{
		ft_rotate(stk_a, 'a');
		(*data)[2]--;
	}
	else 
	{
		ft_rotate(stk_b, 'b');
		(*data)[3]--;
	}
}

void	ft_pathern1(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[2] > 0 && (*data)[3] > 0)
	{
		ft_rrr(stk_a, stk_b);
		(*data)[2]--;
		(*data)[3]--;
	}
	else if ((*data)[2] > 0 && (*data)[3] == 0)
	{
		ft_rev_rotate(stk_a, 'a');
		(*data)[2]--;
	}
	else 
	{
		ft_rev_rotate(stk_b, 'b');
		(*data)[3]--;
	}
}

void	ft_pathern2(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[2] > 0)
	{	
		ft_rotate(stk_a, 'a');
		(*data)[2]--;
	}
	if ((*data)[3] > 0)
	{	
		ft_rev_rotate(stk_b, 'b');
		(*data)[3]--;
	}
}

void	ft_pathern3(int **data, t_stack *stk_a, t_stack *stk_b)
{
	if ((*data)[2] > 0)
	{	
		ft_rev_rotate(stk_a, 'a');
		(*data)[2]--;
	}
	if ((*data)[3] > 0)
	{	
		ft_rotate(stk_b, 'b');
		(*data)[3]--;
	}
}
