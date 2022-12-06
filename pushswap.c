/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 10:48:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static size_t	ft_size(char **argv)
{
	int	size = 0;
	while (argv[size])
		size++;
	return (size);
}

int	main(int argc, char **argv)
{
	char	**test;
	t_cbuf	*cir;
	int		i = 0;
	int		size;

	ft_pre_check(argc, argv);
	test = ft_prep_list(argv);
	size = ft_size(test);
	if (size == 1)
	{
		printf("one argument\n");
		ft_free(test, NULL, NULL);
		return (0);
	}
	cir = init_stack_a(test, size);
	ft_free(test, NULL, NULL);
	ft_duplicate(cir);
	if (ft_sorted(cir) == TRUE)
	{
		printf("sorted\n");
		ft_free(NULL, NULL, cir);
		return (0);
	}
	while (i <= size - 1)
	{
		printf("%i\n", cir->tab[cir->head + i]);
		i++;
	}
	i = 0;
	ft_free(NULL, NULL, cir);
	return (0);
}
