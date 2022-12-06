/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:19:51 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 10:47:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_add_data(t_cbuf *stack, int data)
{
	ssize_t	size;

	size = stack->max;
	if (((stack->head == 0 && stack->tail == size - 1) 
		|| (stack->tail == (stack->head - 1) % (size - 1))) && size != 2)
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

t_cbuf	*set_stack(int size)
{
	t_cbuf	*stack;
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(int *) * size);
	if (tab == NULL)
		return (NULL);
	stack = cbuf_init(tab, size);
	if (stack == NULL)
	{
		free (tab);
		return (NULL);
	}
	return (stack);
}

t_cbuf	*init_stack_a(char **list, int size)
{
	t_cbuf	*stack;
	long	output;
	int		i;

	i = 0;
	stack = set_stack(size);
	if (stack == NULL)
	{
		ft_free (list, NULL, NULL);
		exit (0);
	}
	while (list[i])
	{
		output = ft_atoi(list[i]);
		if (output >= -1 && output <= 0 && ft_overflow(list[i], output) == 1)
		{
			ft_free(list, NULL, stack);
			ft_errors();
		}
		ft_add_data(stack, output);
		i++;
	}
	return (stack);
}
