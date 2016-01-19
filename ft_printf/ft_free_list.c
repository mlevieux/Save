/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:49:21 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/11 10:37:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_free_list(T_LIST **start)
{
	if ((*start)->next != NULL)
		ft_free_list(&(*start)->next);
	free(*start);
}