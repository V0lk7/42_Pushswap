/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:56:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/05 08:23:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static char	**ft_set_list(char **argv)
{
	char	**list;
	int		i;

	list = ft_prep_list(argv);
	i = 0;
	while (list[i])
	{
		if (ft_check(list[i]) == FALSE)
		{
			ft_free(list, NULL, NULL);
			ft_errors();
		}
		i++;
	}
	return (list);
}

static t_stack	*ft_set(int argc, char **argv)
{
	char	**list;
	t_stack	*stack;

	if (argc < 2)
		exit (0);
	if (ft_pre_check == FALSE)
		ft_errors();
	list = ft_set_list(argv);
	stack = ft_init_stack(ft_size_list(list), list);
	if (stack == NULL)
	{
		ft_free(list, NULL, NULL);
		ft_errors();
	}
	ft_free(list, NULL, NULL);
	return (stack);
}

static t_bool	ft_do_move(t_stack *stk_a, t_stack *stk_b, char *input)
{
	char		**movements;
	char		*str;
	int			index;
	t_bool		flag;
	t_movements	*functions[11];

	flag = TRUE;
	ft_init_ftab(functions);
	str = "sa\n pa\n ra\n rra\n sb\n pb\n rb\n rrb\n ss\n rr\n rrr\n";
	movements = ft_split(str, ' ');
	if (movements == NULL)
	{
		ft_free(NULL, input, stk_a);
		ft_free(NULL, NULL, stk_b);
		ft_errors();
	}
	index = ft_index_move(movements, input);
	if (index < 11)
		functions[index](stk_a, stk_b);
	else
		flag = FALSE;
	ft_free(movements, NULL, NULL);
	return (flag);
}

static int	ft_read_input(t_stack *stk_a, t_stack *stk_b)
{
	int		flag1;
	int		flag2;
	char	*std_input;

	flag1 = TRUE;
	flag2 = TRUE;
	std_input = get_next_line(0);
	if (ft_is_sorted(stk_a->tab, stk_a->max) && std_input != NULL)
		flag1 = FALSE;
	while (std_input)
	{
		if (flag2 == TRUE)
			flag2 = ft_do_move(stk_a, stk_b, std_input);
		else
			ft_do_move(stk_a, stk_b, std_input);
		free(std_input);
		std_input = get_next_line(0);
	}
	if (flag2 == FALSE)
		return (1);
	else if (flag1 == FALSE)
		return (0);
	else
		return (3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		answer;

	stack_a = ft_set(argc, argv);
	stack_b = ft_init_stack(stack_a->max, NULL);
	if (stack_b == NULL)
	{
		ft_free(NULL, NULL, stack_b);
		ft_errors();
	}
	answer = ft_read_input(stack_a, stack_b);
	ft_answers(stack_a, stack_b, answer);
	ft_free(NULL, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
