/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/14 15:51:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_call_wstring(wchar_t *wstring, T_LIST *trail, wchar_t *print)
{
	if (ft_check_wchar(wstring))
		ft_repstr(print, trail, wstring);
	if (trail->mod)
		ft_error(1);
	wstring = ft_wstring_apply_mod(trail, wstring);
	wstring = ft_set_length(trail, wstring);
	wstring = ft_wstring_set_width(wstring, trail);
	wstring = ft_wstring_apply_flag(wstring, trail);
	ft_repstr(print, trail, wstring);
}