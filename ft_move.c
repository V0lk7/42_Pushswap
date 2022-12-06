/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:56:43 by jduval            #+#    #+#             */
/*   Updated: 2022/12/06 16:07:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_element_nbr(t_cbuf *stack)
{

}

void	ft_swap_a(t_cbuf *stack)
{
	int	tmp;
	if (!stack)
		return ;
	tmp = stack->tab[stack->head];
	stack->tab[stack->head] =  stack->tab[stack->head + 1];
	stack->tab[stack->head  + 1] = tmp;
	ft_putstr("sa");
}

void	ft_swap_b(t_cbuf *stack)
{
	int	tmp;
	if (cbuf_empty(stack) == TRUE)
		return ;
	tmp = stack->tab[stack->head];
	stack->tab[stack->head] =  stack->tab[stack->head + 1];
	stack->tab[stack->head  + 1] = tmp;
	ft_putstr("sb");
}

void	ft_swap_both(t_cbuf *stack_a, t_cbuf *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack b);
}

void	ft_push_a(t_cbuf *stack_a, t_cbuf *stack_b)
{
	ssize_t	top;
	ssize_t	bot;

	top = stack_a->head;
	bot = stack_a->tail;
	if (cbuf_full(stack_a) == TRUE)
		return ;
	if (top == 0 && bot < stack->max)
	{
		top = stack_a->max;
		stack_a->head = stack_a->max;
		stack_a->tab[top] = stack_b->tab[stack_b->head];
	}
	
}
