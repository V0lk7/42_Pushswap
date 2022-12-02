/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:42:35 by jduval            #+#    #+#             */
/*   Updated: 2022/11/29 08:58:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_errors(int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Errors\n", 2);
		exit (0);
	}
	exit (0);
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
				ft_errors(1);
			if (ft_isdigit(argv[i][j]) == 1)
				k++;
			j++;
		}
		if (k == 0)
			ft_errors(1);
		i++;
	}
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((size_t)i != ft_strlen(str))
		return (1);
	return (0);
}
