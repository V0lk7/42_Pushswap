/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/12/16 14:41:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void 	ft_display(t_stack *stack, size_t size, char c)
{
	size_t	i = 0;

	printf("stack %c = ", c);
	while (i < size)
	{
		printf("%i|", stack->tab[i]);
		i++;
	}
	printf("\n");
	return ;
}
/*
static void	ft_move(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	size_t	i;

	i = size;

	return ;
}
*/
int	main(int argc, char **argv)
{
	char	**list;
	size_t	size;
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t		average;

	ft_pre_check(argc, argv);
	list = ft_prep_list(argv);
	size = size_list(list);
	if (size == 1)
	{
		ft_free(list, NULL, NULL);
		return (0);
	}
	stack_a = ft_init_stack(size, list);
	stack_b = ft_init_stack(size, NULL);
	ft_display(stack_a, size, 'a');
	stack_a = ft_normalize(stack_a);
	average = ft_average(stack_a->tab, stack_a->max);
	printf("average = %zu\n", average);
	ft_display(stack_a, size, 'a');
	ft_free(list, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
