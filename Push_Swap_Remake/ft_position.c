/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:17:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction est sensee renvoyer la position relative du premier element de b
 * par rapport a la pile a
 **/

int		ft_position(t_stack *alpha)
{
	t_stack	*tmpa;
	t_stack *tmpb;
	int		i;
	int		j;
	
	i = 0;
	j = -2;
	tmpa = alpha;
	tmpb = alpha->prev;
	while (tmpa->next->first != 1 && tmpb->first != 1)
	{
		if (tmpa->next->element < tmpa->element)
			return (i);
		if (tmpb->prev->element > tmpb->element)
			return (j);
		i++;
		j--;
		tmpa = tmpa->next;
		tmpb = tmpb->prev;
	}
	return (0);
}
