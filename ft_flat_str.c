/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flat_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:53:14 by jduval            #+#    #+#             */
/*   Updated: 2022/11/29 16:02:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	*ft_set_space(char *str)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) + 1;
	new = malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = ' ';
	if (str)
		i++;
	new[i] = '\0';
	free (str);
	return (new);
}

char	**ft_prep_list(char **argv)
{
	int		i;
	char 	*str;
	char	**list;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		str = ft_strjoin_free(str, argv[i]);
		str = ft_set_space(str);
		i++;
	}
	list = ft_split(str, ' ');
	i = 0;
	while (list[i])
	{
		if (ft_check(list[i]) == 1)
		{
			ft_free(list, NULL, NULL);
			ft_errors(1);
		}
		i++;
	}
	free (str);
	return (list);
}
