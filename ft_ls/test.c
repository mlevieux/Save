/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/22 17:21:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

char	*ft_parse(char **argv, char ***file_names);

int main(int argc, char **argv)
{
	char	*options;
	char	**file_names;
	int		i;

	i = 0;
	file_names = (char**)malloc(sizeof(char*) * argc);
	options = ft_parse(argv, &file_names);
	printf("Options : %c, %c, %c, %c, %c\n", options[0] ? 'a' : '0', options[1] ? 'l' : '0', options[2] ? 'R' : '0', options[3] ? 'r' : '0', options[4] ? 't' : '0');

	printf("Files'name :\n");
	while (file_names[i] != NULL)
		printf("\t%s\n", file_names[i++]);

	return (0);
}
