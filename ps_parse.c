/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:42:35 by jduval            #+#    #+#             */
/*   Updated: 2022/12/09 11:07:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	size_list(char **list)
{
	int	size;

	size = 0;
	while(list[size])
		size++;
	return (size);
}

void	ft_pre_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	if (argc < 2)
		exit(0);
	while (argv[i])
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				ft_errors();
			if (ft_isdigit(argv[i][j]) == 1)
				k++;
			j++;
		}
		if (k == 0)
			ft_errors();
		i++;
	}
}

int	ft_check(char *str)
{
	size_t	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i != ft_strlen(str))
		return (1);
	return (0);
}

int	ft_overflow(char *list, int output)
{
	size_t	i;

	i = 0;	
	if (output == -1)
	{
		if (ft_strlen(list) == 2 && list[0] == '-' && list[1] == '1')
			return (0);
	}
	if (output == 0)
	{
		while (list[i] == '0')
			i++;
		if (list[i] != '\0')
			return (0);
	}
	return (1);
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
