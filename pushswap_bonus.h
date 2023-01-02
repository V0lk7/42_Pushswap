/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:17:50 by jduval            #+#    #+#             */
/*   Updated: 2023/01/02 09:56:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "libft.h"

typedef struct s_stack
{
	int		*tab;
	size_t	max;
}	t_stack;

typedef void	t_movements(t_stack *stack_a, t_stack *stack_b);

//			In ps_flat_bonus.c
char		*ft_set_space(char *str);
char		**ft_prep_list(char **argv);
//			In ps_parse_bonus.c
size_t		ft_size_list(char **list);
t_bool		ft_pre_check(char **argv);
t_bool		ft_check(char *str);
t_bool		ft_overflow(char *list, int output);
t_bool		ft_duplicate(int *tab, size_t size);
//			In ps_set_stack_bonus.c
t_bool		ft_add_data(int *tab, char **list);
void		ft_add_zero(int *tab, size_t size);
t_bool		ft_set_a(t_stack *stack, char **list, size_t size);
t_stack		*ft_init_stack(size_t size, char **list);
//			In ps_utils_bonus.c
void		ft_errors(void);
void		ft_free(char **tab, char *str, t_stack *stack);
char		*ft_strjoin_free(char *s1, char const *s2);
t_bool		ft_is_sorted(int *tab, size_t size);
int			ft_index_move(char **list, char *input);
//			In ps_moves_a_bonus.c
void		ft_sa(t_stack *stack_a, t_stack *stack_b);
void		ft_pa(t_stack *stack_a, t_stack *stack_b);
void		ft_ra(t_stack *stack_a, t_stack *stack_b);
void		ft_rra(t_stack *stack_a, t_stack *stack_b);
//			In ps_moves_b_bonus.c
void		ft_sb(t_stack *stack_a, t_stack *stack_b);
void		ft_pb(t_stack *stack_a, t_stack *stack_b);
void		ft_rb(t_stack *stack_a, t_stack *stack_b);
void		ft_rrb(t_stack *stack_a, t_stack *stack_b);
//			In ps_double_moves_bonus.c
void		ft_adjust(t_stack *stack);
void		ft_adjust_filled(t_stack *stack);
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_rrr(t_stack *stack_a, t_stack *stack_b);
//			In checker_utils2_bonus.c
void		ft_init_ftab(t_movements **functions);
void		ft_answers(t_stack *stk_a, t_stack *stk_b, int answer);
#endif
