/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:29:47 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 10:33:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bool	ft_sorted(t_cbuf *stack)
{
	int i;
	int	j;

	if (stack->max == 1)
		return (TRUE);
	i = stack->head;
	while (i < stack->tail)
	{
		j = i + 1;
		if (stack->tab[i] >= stack->tab[j])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_errors(void)
{
	ft_putstr_fd("Errors\n", 2);
	exit (0);
}

void	ft_free(char **tab, char *str, t_cbuf *buffer)
{
	int	i;

	i = 0;
	if (tab && *tab)
	{
		while (tab[i])
		{
			free (tab[i]);
			i++;
		}
		free (tab);
	}
	if (str)
		free (str);
	if (buffer && buffer->tab)
	{
		free(buffer->tab);
		free(buffer);
	}
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	size_alloc;
	char	*new_s;
	size_t	size_srcs;

	size_alloc = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = malloc(size_alloc * sizeof(char));
	if (!new_s)
	{
		free (s1);
		return (NULL);
	}
	size_alloc = ft_strlen(s1) + 1;
	ft_strlcpy(new_s, s1, size_alloc);
	size_alloc = ft_strlen(new_s);
	size_srcs = ft_strlen(s1) + ft_strlen(s2) + 1;
	ft_strlcpy(&new_s[size_alloc], s2, size_srcs);
	free (s1);
	return (new_s);
}
