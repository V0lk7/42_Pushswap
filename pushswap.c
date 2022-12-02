/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:30:45 by jduval            #+#    #+#             */
/*   Updated: 2022/11/29 15:59:36 by jduval           ###   ########.fr       */
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
	cir = set_stack(test, size);
	ft_free(test, NULL, NULL);
	while (i < size)
	{
		printf("%i\n", cir->tab[cir->head + i]);
		i++;
	}
	ft_free(NULL, NULL, cir);
	return (0);
}
