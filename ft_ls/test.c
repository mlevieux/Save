/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:33:02 by mlevieux         ###   ########.fr       */
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
#include <grp.h>
#include <time.h>

int main(int argc, char **argv)
{
	struct dirent *dir;
	DIR *open;
	struct stat *stat;
	struct group *grp;
	struct passwd *pwd;

	open = opendir("./");
	stat = (struct stat*)malloc(sizeof(struct stat));
	if ((dir = readdir(open)) != NULL)
	{
		lstat("./a.out", stat);
		if (stat->st_mode & S_IRWXU)
		printf("ca marche wesh\n");
	}
	return (0);
}
