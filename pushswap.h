/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:15 by jduval            #+#    #+#             */
/*   Updated: 2022/12/02 10:45:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

void	ft_free(char **tab, char *str, t_cbuf *buffer);
char	*ft_strjoin_free(char *s1, char const *s2);
void	ft_errors(int flag);
void	ft_pre_check(int argc, char **argv);
int		ft_check(char *str);
char	**ft_prep_list(char **argv);
void	ft_add_data(t_cbuf *stack, int data);
t_cbuf	*set_stack(char **list, int size);

#endif
