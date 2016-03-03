/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:25:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 17:24:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sol	*ft_restack(t_stack *alpha, t_stack *beta)
{
	t_sol	*solution;

	while (ft_stack_len(beta) != 0)
	{
		if (alpha->element > beta->element &&
				(alpha->prev->element < beta->element ||
				alpha->prev->element > alpha->element))
			ft_add_sol(solution, ft_pa(beta, alpha));
		else
			ft_add_sol(solution, ft_position(beta, alpha) ? ft_ra(alpha) :
					ft_rra(alpha));
	}
	return (solution);
}
