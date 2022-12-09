/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:16 by jduval            #+#    #+#             */
/*   Updated: 2022/12/09 14:35:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_add_data(int	*tab, char **list, size_t size)
{
	int	i;
	int	j;
	int	output;

	i = size - 1;
	j = 0;
	while (list[j])
	{
		output = ft_atoi(list[j]);
		if (ft_overflow(list[j], output) == 0)
			return (FALSE);
		tab[i] = output;
		i--;
		j++;
	}
	return (TRUE);
}

void	ft_add_zero(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return ;
}

t_bool	set_stack_a(t_stack *stack, char **list, size_t size)
{
	t_bool	flag;

	stack->max = size;
	flag = ft_add_data(stack->tab, list, size);
	flag = ft_duplicate(stack->tab, size);
	return (flag);
}

t_stack	*ft_init_stack(size_t size, char **list)
{
	t_stack	*stack;
	t_bool	flag;

	flag = TRUE;
	stack = malloc(sizeof(t_stack));
	stack->tab = malloc(sizeof(int) * size);
	if (stack->tab == NULL || stack == NULL)
	{
		ft_free(list, NULL, stack);
		ft_errors();
	}
	if (list)
		flag = set_stack_a(stack, list, size);
	else
	{
		stack->max = 0;
		ft_add_zero(stack->tab, size);
	}
	if (flag == FALSE)
	{
		ft_free(list, NULL, stack);
		ft_errors();
	}
	return (stack);
}
