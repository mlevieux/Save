/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:55:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 17:42:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*trail_minus(char *result, T_LIST *trail, int i)
{
	char	*insert;
	
	if (trail->z_pad && !(trail->accuracy > -1 && trail->type == 'd'))
	{
		insert = ft_strset(ft_strnew(trail->width - ft_strlen(result)),
				trail->width - ft_strlen(result), '0');
		result = ft_repstr(result,
			(result[i] == '+' || result[i] == '-') ? i = i + 1 : i, i, insert);
	}
	else
	{
		insert = ft_strset(ft_strnew(trail->width - ft_strlen(result)),
				trail->width - ft_strlen(result), ' ');
		result = ft_repstr(result, i, i, insert);
	}
	free(insert);
	return (result);
}

char	*ft_set_width(char *result, T_LIST *trail)
{
	int		i;
	char	*insert;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != '+' && result[i] != '-' &&
			result[i] != 0 && (trail->type == 'd' || trail->type == 'f') &&
			trail->format != 'x' && trail->format != 'X')
		i++;
	if (trail->format == 'p' && trail->z_pad && !trail->minus)
		i = 2;
	if (trail->width > (int)ft_strlen(result))
	{
		if (!(trail->minus))
			result = trail_minus(result, trail, i);
		else
		{
			insert = ft_strset(ft_strnew(trail->width - ft_strlen(result)),
						trail->width - ft_strlen(result), ' ');
			result = ft_repstr(result, ft_strlen(result), ft_strlen(result),
					insert);
			free(insert);
		}
	}
	return (result);
}
