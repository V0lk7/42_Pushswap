/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/12/09 11:08:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	char	**list;
	size_t	i = 0;
	size_t	size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_pre_check(argc, argv);
	list = ft_prep_list(argv);
	size = size_list(list);
	stack_a = ft_init_stack(size, list);
	stack_b = ft_init_stack(size, NULL);
	if (size == 1)
	{
		ft_free(list, NULL, NULL);
		return (0);
	}
	printf("|size = %zu|\nlist = ", size);
	while (list[i])
	{
		printf("%s|", list[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < size)
	{
		printf("%i|", stack_a->tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < size)
	{
		printf("%i|", stack_b->tab[i]);
		i++;
	}
	printf("\n");
	if (ft_is_sorted(stack_a->tab, stack_a->max) == TRUE)
		printf("Sorted\n");
	else
		printf("Not sorted\n");
	ft_free(list, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
