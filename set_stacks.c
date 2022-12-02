/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:19:51 by jduval            #+#    #+#             */
/*   Updated: 2022/11/29 16:31:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_add_data(t_cbuf *stack, int data)
{
	ssize_t	size;

	size = stack->max;
	if ((stack->head == 0 && stack->tail == size - 1) 
		|| (stack->tail == (stack->head - 1) % (size - 1)))
		return ;
	else if (stack->head == -1)
	{
		stack->head = 0;
		stack->tail = 0;
		stack->tab[stack->tail] = data;
	}
	else if (stack->tail == size - 1 && stack->head != 0)
	{
		stack->tail = 0;
		stack->tab[stack->tail] = data;
	}
	else
	{
		stack->tail++;
		stack->tab[stack->tail] = data;
	}
}

t_cbuf	*set_stack(char	**list, int size)
{
	t_cbuf	*stack;
	int		*tab;
	int		output;
	int		i;

	i = 0;
	tab = malloc(sizeof(int *) * size);
	stack = cbuf_init(tab, size);
	if (stack == NULL)
	{
		ft_free(list, NULL, NULL);
		exit (0);
	}
	while (list[i])
	{
		output = ft_atoi(list[i]);
		if (output > 2147483647 || output < -2147483648)
		{
			reset_cbuf(stack);
			ft_free(list, NULL, NULL);
			exit (0);
		}
		i++;
	}
	return (stack);
}
