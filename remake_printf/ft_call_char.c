/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:50:16 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 17:41:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_call_char(wchar_t wc, T_LIST *trail, char **print, int *buffer)
{
	char	*result;
	int		state_value;

	state_value = 1;
	result = (char*)ft_transfer_wchar(wc, &(trail->oct_num));
	if (trail->width < 0)
	{
		trail->width = -1 * trail->width;
		trail->minus = 1;
	}
	if (wc == 0)
	{
		trail->width--;
		(*buffer)++;
	}
	result = ft_set_width(result, trail);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	free(result);
	return (state_value);
}
