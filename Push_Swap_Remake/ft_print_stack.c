/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 11:32:15 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 14:08:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *alpha)
{
	t_stack *tmp;

	printf("\t\tTMP->ELEMENT : %d\n", alpha->element);
	tmp = alpha->next;
	while (tmp->first == 0)
	{
		printf("\t\tTMP->ELEMENT : %d\n", tmp->element);
		fflush(stdout);
		tmp = tmp->next;
	}
}
