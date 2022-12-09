/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:08:16 by jduval            #+#    #+#             */
/*   Updated: 2022/12/09 11:02:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_add_data(int	*tab, char **list)
{
	int	i;
	int	output;

	i = 0;
	while (list[i])
	{
		output = ft_atoi(list[i]);
		if (ft_overflow(list[i], output) == 0)
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

t_stack	*ft_init_stack(size_t size, char **list)
{
	t_stack	*stack;
	t_bool	flag;

	flag = TRUE;
	stack = malloc(sizeof(t_stack));
	stack->tab = malloc(sizeof(int) * size);
	if (stack->tab == NULL)
	{
		ft_free(list, NULL, stack);
		ft_errors();
	}
	stack->max = size;
	if (list)
	{
		flag = ft_add_data(stack->tab, list);
		flag = ft_duplicate(stack->tab, size);
	}
	else 
		ft_add_zero(stack->tab, size);
	if (flag == FALSE)
	{
		ft_free(list, NULL, stack);
		ft_errors();
	}
	return (stack);
}
