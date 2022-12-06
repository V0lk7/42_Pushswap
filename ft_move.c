/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:56:43 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 09:01:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(t_cbuf *stack)
{
	int	tmp;
	if (!stack)
		return ;
	tmp = stack->tab[stack->head];
	stack->tab[stack->head] =  stack->tab[stack->head + 1];
	stack->tab[stack->head  + 1] = tmp;
}
