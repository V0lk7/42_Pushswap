/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:10:51 by jduval            #+#    #+#             */
/*   Updated: 2022/12/30 18:37:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_init_ftab(t_movements **functions)
{
	functions[0] = ft_sa;
	functions[1] = ft_pa;
	functions[2] = ft_ra;
	functions[3] = ft_rra;
	functions[4] = ft_sb;
	functions[5] = ft_pb;
	functions[6] = ft_rb;
	functions[7] = ft_rrb;
	functions[8] = ft_ss;
	functions[9] = ft_rr;
	functions[10] = ft_rrr;
}
