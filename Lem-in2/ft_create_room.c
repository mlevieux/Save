/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:26:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/15 11:34:21 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_number(char *str)
{
	int		i;
	int		num;

	num = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			num = 0;
		i++;
	}
	return (num ? 1 : 0);
}

t_room		*ft_create_room(char **tab, int is_end, int is_start)
{
	t_room	*new;

	if (tab && (!tab[0] || !tab[1] || !tab[2]))
		ft_block("It's : name x y, it isn't complicated is it?");
	new = (t_room*)malloc(sizeof(t_room));
	new->name = tab ? ft_strdup(tab[0]) : NULL;
	new->links = NULL;
	new->is_end = is_end;
	new->is_start = is_start;
	new->is_full = 0;
	new->x = tab ? ft_atoi(tab[1]) : 0;
	new->y = tab ? ft_atoi(tab[2]) : 0;
	if (tab && ((!new->x && !is_number(tab[1])) ||
		(!new->y && !is_number(tab[2]))))
		ft_block("X and Y must be numbers since they're coordinates...");
	return (new);
}
