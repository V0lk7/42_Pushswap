/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:15 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 10:31:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cbuf
{
	int *tab;
	ssize_t	head;
	ssize_t	tail;
	ssize_t	max;
	t_bool	full;
}	t_cbuf;

void		ft_free(char **tab, char *str, t_cbuf *buffer);
char		*ft_strjoin_free(char *s1, char const *s2);
void		ft_errors(void);
void		ft_pre_check(int argc, char **argv);
int			ft_check(char *str);
int			ft_overflow(char *list, int output);
void		ft_duplicate(t_cbuf *stack);
char		**ft_prep_list(char **argv);
void		ft_add_data(t_cbuf *stack, int data);
t_cbuf		*cbuf_init(int *tab, size_t size);
t_bool		cbuf_empty(t_cbuf *buffer);
t_bool		cbuf_full(t_cbuf *buffer);
void		reset_cbuf(t_cbuf *buffer);
size_t		cbuf_size(t_cbuf *buffer);
t_cbuf		*init_stack_a(char **list, int size);
t_cbuf		*set_stack(int size);
t_bool		ft_sorted(t_cbuf *stack);

#endif
