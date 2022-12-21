/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:15 by jduval            #+#    #+#             */
/*   Updated: 2022/12/21 15:09:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include "printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*tab;
	size_t	max;
}	t_stack;

/*	in pushswap.c		*/
void		ft_display(t_stack *stack, size_t size, char c);
/*	in ps_flat.c		*/
char		*ft_set_space(char *str);
char		**ft_prep_list(char **argv);
/*	in ps_parse.c		*/
size_t		size_list(char **list);
void		ft_pre_check(int argc, char **argv);
int			ft_check(char *str);
int			ft_overflow(char *list, int output);
t_bool		ft_duplicate(int *tab, size_t size);
/*	in ps_utils.c		*/
void		ft_errors(void);
void		ft_free(char **tab, char *str, t_stack *stack);
char		*ft_strjoin_free(char *s1, char const *s2);
size_t		ft_find_max(int *tab, size_t len);
size_t		ft_find_min(int *tab, size_t max);
/*	 in ps_set_stack.c	*/
t_bool		ft_add_data(int *tab, char **list);
void		ft_add_zero(int *tab, size_t size);
t_bool		set_stack_a(t_stack *stack, char **list, size_t size);
t_stack		*ft_init_stack(size_t size, char **list);
t_stack		*ft_normalize(t_stack *stk_a);
/*	in ps_stats.c		*/
t_bool		ft_is_sorted(int *tab, size_t size);
size_t		ft_count_sa(t_stack *stack, int value, t_bool flag);
size_t		ft_count_sb(size_t len, int index, t_bool flag);
size_t		ft_abs(size_t a, size_t b);
size_t		ft_nbr_move(t_stack *stk_a, t_stack *stk_b, size_t i, t_bool flag);
/*	in ps_move.c		*/
void		ft_swap(t_stack *stack, char c);
void		ft_push(t_stack *give, t_stack *take, char c);
void		ft_rotate(t_stack *stack, char c);
void		ft_rev_rotate(t_stack *stack, char c);
/*	in ps_move2.c		*/
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_rrr(t_stack *stack_a, t_stack *stack_b);
/*	in ps_alg_spe.c		*/
//void	ft_algo_three(t_stack *stk, char c);
//void	ft_algo_four(t_stack *stk_a, t_stack *stk_b);

/*	in ps_algorithm.c	*/
void		ft_algorithm(t_stack *stk_a, t_stack *stk_b);
size_t		ft_chosen_one(t_stack *stk_a, t_stack *stk_b);
#endif
