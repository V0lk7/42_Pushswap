/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/12/13 17:08:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
static void 	ft_display(t_stack *stack, size_t size, char c)
{
	size_t	i = 0;

	printf("stack %c :\n", c);
	printf("stack = ");
	while (i < size)
	{
		printf("%i|", stack->tab[i]);
		i++;
	}
	printf("\nindex = ");
	i = 0;
	while (i < size)
	{
		printf("%zu|", i);
		i++;
	}
	printf("\n");
	return ;
}

static void	ft_move(t_stack *stack_a, t_stack *stack_b, size_t size)
{
	size_t	i;

	i = size;
	printf("Before pushb\n");
	ft_display(stack_a, size, 'a');
	printf("After pushb\n");
	ft_push(stack_a, stack_b, 'b');
	ft_display(stack_a, size, 'a');
	ft_display(stack_b, size, 'b');
	printf("After pushai\n");
	ft_push(stack_b, stack_a, 'a');
	ft_display(stack_a, size, 'a');
	ft_display(stack_b, size, 'b');

	return ;
}

int	main(int argc, char **argv)
{
	char	**list;
	size_t	size;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	ft_move(stack_a, stack_b, size);
/*	if (ft_is_sorted(stack_a->tab, stack_a->max) == TRUE)
		printf("Sorted\n");
	else
		printf("Not sorted\n");*/
	ft_free(list, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
