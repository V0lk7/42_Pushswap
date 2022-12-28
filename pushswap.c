/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/12/28 16:55:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//#define DEBUG

void 	ft_display(t_stack *stack, size_t size, char c)
{
#ifdef DEBUG
#include <stdio.h>
	size_t	i = 0;

	printf("stack %c = ", c);
	while (i < size)
	{
		printf("%i|", stack->tab[i]);
		i++;
	}
	printf("\n");
	return ;
#else
	(void) stack;
	(void) size;
	(void) c;
#endif
}

static char	**ft_set_list(char **argv)
{
	char	**list;
	int		i;

	i = 0;
	if (ft_pre_check(argv) == FALSE)
		ft_errors();
	list = ft_prep_list(argv);
	while (list[i])
	{
		if (ft_check(list[i]) == FALSE)
		{
			ft_free(list, NULL, NULL);
			ft_errors();
		}
		i++;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	char	**list;
	size_t	size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit (0);
	list = ft_set_list(argv);
	size = ft_size_list(list);
	stack_a = ft_init_stack(size, list);
	stack_b = ft_init_stack(size, NULL);
	ft_free(list, NULL, NULL);
	ft_algorithm(stack_a, stack_b);
	ft_display(stack_a, stack_a->max, 'a');
	ft_free(NULL, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
