/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:04:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/21 09:55:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i])
		free(ants[i++]);
	free(ants);
	printf("Ants were freed successfully\n");
	fflush(stdout);
	i = 0;
	while (rooms[i]->name)
		free(rooms[i++]);
	free(rooms);
	printf("Rooms were freed successfully\n");
	fflush(stdout);
	while (paths[i])
	{
		while (paths[i])
		{
			free(paths[i]);
			paths[i] = paths[i]->next;
		}
		i++;
	}
	free(paths);
	printf("Paths were freed successfully\n");
	fflush(stdout);
}
