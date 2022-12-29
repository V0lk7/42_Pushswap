/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_flat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:53:14 by jduval            #+#    #+#             */
/*   Updated: 2022/12/28 14:08:22 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_set_space(char *str)
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
	char	*str;
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
	free (str);
	if (list == NULL)
		ft_errors();
	return (list);
}
