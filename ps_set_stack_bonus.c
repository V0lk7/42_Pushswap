/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:05:50 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 16:06:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_bool	ft_add_data(int	*tab, char **list)
{
	int	i;
	int	output;

	i = 0;
	while (list[i])
	{
		output = ft_atoi(list[i]);
		if (ft_overflow(list[i], output) == FALSE)
			return (FALSE);
		tab[i] = output;
		i++;
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

t_bool	ft_set_a(t_stack *stack, char **list, size_t size)
{
	t_bool	flag;

	stack->max = size;
	flag = ft_add_data(stack->tab, list);
	if (flag == FALSE)
		return (flag);
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
		flag = ft_set_a(stack, list, size);
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
