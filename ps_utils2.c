/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:22:09 by jduval            #+#    #+#             */
/*   Updated: 2022/12/23 16:52:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_positive_min(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = i;
	while (i < size - 1)
	{
		if (tab[i] > 0 && tab[tmp] > tab[i + 1])
			tmp = i + 1;
		i++;
	}
	return (tmp);
}

int	ft_negative_max(int *tab, size_t size)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = i;
	while (i < size - 1)
	{
		if (tab[i] < 0 && tab[tmp] < tab[i + 1])
			tmp = i + 1;
		i++;
	}
	return (tmp);
}
