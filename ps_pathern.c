/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pathern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:57:41 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 09:24:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_data	ft_pathern0(t_data data, t_stack *stk_a, t_stack *stk_b)
{
	if (data.move_a > 0 && data.move_b > 0)
	{
		ft_rr(stk_a, stk_b);
		data.move_a--;
		data.move_b--;
		return (data);
	}
	else if (data.move_a > 0 && data.move_b == 0)
	{
		ft_rotate(stk_a, 'a');
		data.move_a--;
		return (data);
	}
	else
	{
		ft_rotate(stk_b, 'b');
		data.move_b--;
		return (data);
	}
}

t_data	ft_pathern1(t_data data, t_stack *stk_a, t_stack *stk_b)
{
	if (data.move_a > 0 && data.move_b > 0)
	{
		ft_rrr(stk_a, stk_b);
		data.move_a--;
		data.move_b--;
		return (data);
	}
	else if (data.move_a > 0 && data.move_b == 0)
	{
		ft_rev_rotate(stk_a, 'a');
		data.move_a--;
		return (data);
	}
	else
	{
		ft_rev_rotate(stk_b, 'b');
		data.move_b--;
		return (data);
	}
}

t_data	ft_pathern2(t_data data, t_stack *stk_a, t_stack *stk_b)
{
	if (data.move_a > 0)
	{	
		ft_rotate(stk_a, 'a');
		data.move_a--;
		return (data);
	}
	if (data.move_b > 0)
	{	
		ft_rev_rotate(stk_b, 'b');
		data.move_b--;
		return (data);
	}
	return (data);
}

t_data	ft_pathern3(t_data data, t_stack *stk_a, t_stack *stk_b)
{
	if (data.move_a > 0)
	{	
		ft_rev_rotate(stk_a, 'a');
		data.move_a--;
		return (data);
	}
	if (data.move_b > 0)
	{	
		ft_rotate(stk_b, 'b');
		data.move_b--;
		return (data);
	}
	return (data);
}
