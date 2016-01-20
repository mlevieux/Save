/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 13:53:31 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 14:29:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putwstr(wchar_t *wstring)
{
	int i;

	i = 0;
	utf8();
	while (wstring[i] != 0)
	{
		write(1, (wstring + i), 1);
		i++;
	}
}
