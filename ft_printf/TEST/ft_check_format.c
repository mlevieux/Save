/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:43:12 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/22 10:59:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_zero(int *flag, int *dot, int *mod, int *star)
{
	*dot = 0;
	*mod = 0;
	*flag = 0;
	*star = 0;
}

static int		ft_inner_loop(int tab[], char *format, int *i)
{
	while (!ft_what_type(format[*i]) && format[*i] != 0)
	{
		if (ft_is_flag(format[*i])/* && !tab[2] && !tab[1]*/ && tab[0] < 3)
			tab[0]++;
		else if (format[*i] == '*' && tab[3] < 2)
		{
			tab[3]++;
			*i = *i + 1;
		}
		else if (format[*i] == '.' && (ft_isdigit(format[*i + 1]) ||
				format[*i + 1] == '*') /*&& !tab[2]*/ && !tab[1])
		{
			tab[1] = 1;
			tab[3]++;
		}
		else if (ft_is_mod(format[*i]) && tab[2] <= 108 && tab[2] != 76)
			tab[2] += format[*i];
		else if (ft_isdigit(format[*i]) && format[*i] != 0)
			while (ft_isdigit(format[*i + 1]))
				(*i)++;
		else
			return (0);
		if (format[*i] != 0 && !ft_what_type(format[*i]))
			(*i)++;
	}
	return (1);
}

int				ft_check_format(char *format)
{
	int	i;
	int tab[4];

	i = -1;
	while (format[++i] != 0)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ft_zero(&tab[0], &tab[1], &tab[2], &tab[3]);
			i++;
			if (!ft_inner_loop(tab, format, &i) || !ft_what_type(format[i]))
				return (0);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			++i;
	}
	return (1);
}