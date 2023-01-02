/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:42:35 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 15:42:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

size_t	ft_size_list(char **list)
{
	int	size;

	size = 0;
	while (list[size])
		size++;
	return (size);
}

t_bool	ft_pre_check(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (argv[i])
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				return (FALSE);
			if (ft_isdigit(argv[i][j]) == 1)
				k++;
			j++;
		}
		if (k == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_check(char *str)
{
	size_t	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_overflow(char *list, int output)
{
	size_t	i;

	i = 0;
	if (output == -1)
	{
		if (ft_strlen(list) != 2)
			return (FALSE);
	}
	if (output == 0)
	{
		while (list[i] == '0')
			i++;
		if (list[i] != '\0')
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_duplicate(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
