/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:50:44 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 17:30:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strset(char *str, int len, char c)
{
	int i;

	i = 0;
	while (i <= len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
