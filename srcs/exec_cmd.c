/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <jonny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:21:20 by jonny             #+#    #+#             */
/*   Updated: 2021/01/04 11:45:37 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"
#include <unistd.h>

/*
** Create a child process and execute the command in it. Parent process waits
** the child process to finish. read_path() reads the PATH and put it in the
** filepath[MAXCHAR] buffer. We add the filename to the path with ft_strcat()
*/

void	exec_cmd(char *filepath)
{
	char	*args[2];
	pid_t	p1;

	args[0] = filepath;
	args[1] = NULL;
	if (file_exists(args[0]) != 0)
		ft_printf("Command doesn't exist in PATH.\n");
	p1 = fork();
	if (p1 < 0)
	{
		ft_printf("Cannot execute child process.\n");
		exit(-1);
	}
	if (p1 == 0)
	{
		execve(args[0], args, NULL);
		exit(0);
	}
	wait(NULL);
}

/*
** Execute system command. system() function is not allowed in the subject !
** For debug only.
*/

void	exec_syscmd(char *input)
{
	pid_t	p1;

	p1 = fork();
	if (p1 < 0)
	{
		ft_printf("Cannot execute child process.\n");
		exit(-1);
	}
	if (p1 == 0)
	{
		system(input);
		exit(0);
	}
	wait(NULL);
}
