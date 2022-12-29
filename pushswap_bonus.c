/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:17:50 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 15:58:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "libft.h"

typedef struct s_move
{
	int	tab[9];

	tab[0] = void (*ft_swap)(stack_a);
	tab[1] = void (*ft_swap)(stack_b)
}

typedef struct s_stack
{
	int		*tab;
	size_t	max;
}	t_stack;

//			In ps_flat_bonus.c
char		*ft_set_space(char *str);
char		**ft_prep_list(char **argv);
//			In ps_parse_bonus.c
size_t		ft_size_list(char **list);
t_bool		ft_pre_check(char **argv);
t_bool		ft_check(char *str);
t_bool		ft_overflow(char *list, int output);
t_bool		ft_duplicate(int *tab, size_t size);
//			In ps_utils_bonus.c
void		ft_errors(void);
void		ft_free(char **tab, char *str, t_stack *stack);
char		*ft_strjoin_free(char *s1, char const *s2);
t_bool		ft_is_sorted(int *tab, size_t size);
//			In ps_moves_bonus.c
void		ft_swap(t_stack *stack, char c);
void		ft_push(t_stack *give, t_stack *take, char c);
void		ft_rotate(t_stack *stack, char c);
void		ft_rev_rotate(t_stack *stack, char c);
//			In ps_moves2_bonus.c
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
