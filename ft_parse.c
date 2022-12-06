/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:42:35 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 13:14:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_overflow(char *list, int output)
{
	int	i;

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
		if (ft_strlen(list) == (size_t)i)
			return (0);
	}
	return (1);
}

void	ft_duplicate(t_cbuf *stack)
{
	int i;
	int	j;

	i = stack->head;
	while (i < stack->tail)
	{
		j = i + 1;
		while (j <= stack->tail)
		{
			if (stack->tab[i] == stack->tab[j])
			{
				ft_free(NULL, NULL, stack);
				ft_errors();
			}
			j++;
		}
		i++;
	}
}
