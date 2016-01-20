/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wbzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:04:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 18:12:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_wbzero(wchar_t *wstring, int len)
{
	while (len)
	{
		wstring[len] = 0;
		len--;
	}
}
