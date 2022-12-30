/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:56:59 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 18:30:15 by jduval           ###   ########.fr       */
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
	list = ft_set_list(argv);
	stack = ft_init_stack(ft_size_list(list), list);
	ft_free(list, NULL, NULL);
	return (stack);
}

static void	ft_useless_args(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_bool	flag;

	flag = ft_is_sorted(stack_a->tab, stack_a->max);
	if (flag == TRUE && str != NULL)
	{
		ft_printf("KO\n");
		ft_free(NULL, NULL, stack_a);
		ft_free(NULL, NULL, stack_b);
		exit (0);
	}
}

static t_bool	ft_do_move(t_stack *stk_a, t_stack *stk_b, char *input)
{
	char		**movements;
	char		*str;
	int			index;
	t_movements	*functions[11];

	ft_init_ftab(functions);
	str = "sa\n pa\n ra\n rra\n sb\n pb\n rb\n rrb\n ss\n rr\n rrr\n";
	movements = ft_split(str, ' ');
	if (movements == NULL)
		return (FALSE);
	index = ft_index_move(movements, input);
	if (index > 10)
	{
		ft_free(movements, NULL, NULL);
		return (FALSE);
	}
	functions[index](stk_a, stk_b);
	ft_free(movements, NULL, NULL);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*std_input;
	t_bool	flag;

	flag = TRUE;
	stack_a = ft_set(argc, argv);
	stack_b = ft_init_stack(stack_a->max, NULL);
	std_input = get_next_line(0);
	ft_useless_args(stack_a, stack_b, std_input);
	while (std_input && flag == TRUE)
	{
		flag = ft_do_move(stack_a, stack_b, std_input);
		free (std_input);
		std_input = get_next_line(0);
	}
	if (ft_is_sorted(stack_a->tab, stack_a->max) == TRUE
		&& flag == TRUE && stack_b->max == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(NULL, std_input, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
