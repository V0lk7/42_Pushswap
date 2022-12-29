/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:15 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 09:27:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct s_stack
{
	int		*tab;
	size_t	max;
}	t_stack;

typedef struct s_data
{
	size_t	index;
	size_t	pathern;
	size_t	move_a;
	size_t	move_b;
}	t_data;

/*	in pushswap.c		*/
void		ft_display(t_stack *stack, size_t size, char c);
/*	in ps_flat.c		*/
char		*ft_set_space(char *str);
char		**ft_prep_list(char **argv);
/*	in ps_parse.c		*/
size_t		ft_size_list(char **list);
t_bool		ft_pre_check(char **argv);
t_bool		ft_check(char *str);
t_bool		ft_overflow(char *list, int output);
t_bool		ft_duplicate(int *tab, size_t size);
/*	in ps_utils.c		*/
void		ft_errors(void);
void		ft_free(char **tab, char *str, t_stack *stack);
char		*ft_strjoin_free(char *s1, char const *s2);
/*	in ps_data_utils.c		*/
size_t		ft_count_sta(t_stack *stack, size_t i, int value, t_bool flag);
size_t		ft_count_stb(size_t len, int index, t_bool flag);
size_t		ft_find_pos(t_stack *stack, int value, t_bool flag);
int			ft_abs(int a);
size_t		ft_merge(size_t a, size_t b);
/*	 in ps_set_stack.c	*/
t_bool		ft_add_data(int *tab, char **list);
void		ft_add_zero(int *tab, size_t size);
t_bool		ft_set_a(t_stack *stack, char **list, size_t size);
t_stack		*ft_init_stack(size_t size, char **list);
/*	in ps_data.c		*/
t_bool		ft_is_sorted(int *tab, size_t size);
size_t		ft_find_min(int *tab, size_t max);
size_t		ft_nbr_move(t_stack *stk_a, t_stack *stk_b, size_t i, t_bool flag);
t_data		ft_data(t_stack *stk_a, t_stack *stk_b);
t_data		ft_put_count(t_data data, t_stack *stk_a, t_stack *stk_b);
/*	in ps_move.c		*/
void		ft_swap(t_stack *stack, char c);
void		ft_push(t_stack *give, t_stack *take, char c);
void		ft_rotate(t_stack *stack, char c);
void		ft_rev_rotate(t_stack *stack, char c);
/*	in ps_move2.c		*/
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_rrr(t_stack *stack_a, t_stack *stack_b);
/*	in ps_algorithm.c	*/
void		ft_algorithm(t_stack *stk_a, t_stack *stk_b);
/*	in ps_pathern.c		*/
t_data		ft_pathern0(t_data data, t_stack *stk_a, t_stack *stk_b);
t_data		ft_pathern1(t_data data, t_stack *stk_a, t_stack *stk_b);
t_data		ft_pathern2(t_data data, t_stack *stk_a, t_stack *stk_b);
t_data		ft_pathern3(t_data data, t_stack *stk_a, t_stack *stk_b);

#endif
