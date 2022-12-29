/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:56:59 by jduval            #+#    #+#             */
/*   Updated: 2022/12/29 15:04:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_stack *ft_set(int argc, char **argv, t_bool flag)
{
	char	**list;
	t_stack	*stack;

	if (argc < 2)
		exit (0);
	list = ft_set_list(argv);
	if (flag == TRUE)
		stack = ft_init_stack(ft_size_list(list), list);
	else
		stack = ft_init_stack(ft_size_list(list), NULL);
	ft_free(list, NULL, NULL);
	return (stack);
}

static char	**ft_set_list(char **argv)
{
	char	**list;
	int		i;

	if (argc < 2)
		exit (0);
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

static void	ft_args(t_stack *stack_a, t_stack *stack_b, const char *input)
{
	char	**args;
	int		i;
	size_t	size;

	i = 0;
	args = ft_split("sa\n sb\n ra\n rb\n rra\n rrb\n ss\n rr\n rrr\n", ' ');
	if (args == NULL)
	{
		ft_free(NULL, input, stack_a);
		ft_free(NULL, NULL, stack_b);
		ft_errors();
	}
	size = ft_strlen(list[i]);
	while (ft_strncmp(input, list[i], size) != 0 && list[i])
	{
		i++;
		size = ft_strlen(list[i])
	}
	if (list[i] != NULL)
		ft_execute(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	char	*std_input;
	
	stack_a = ft_set(argc, argv, TRUE);
	stack_b = ft_set(argc, argv, FALSE);
	std_input = get_next_line(0);
	ft_useless_args(stack_a, stack_b, std_input);
	while (std_input)
	{
		ft_args(stack_a, stack_b, std_input);
		free (std_input)
		std_input = get_next_line(0);
	}
	if (flag == TRUE && stack_b->max == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(NULL, NULL, stack_a);
	ft_free(NULL, NULL, stack_b);
	return (0);
}
