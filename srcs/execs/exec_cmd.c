/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:21:20 by jonny             #+#    #+#             */
/*   Updated: 2021/05/10 11:59:15 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void	exec_cmd(t_state *st, char **args)
{
	if (create_fork(&g_sig.pid) < 0)
		exit(EXIT_FAILURE);
	if (g_sig.pid == 0)
	{
		execve(*args, args, st->envp);
		if (g_sig.sigint || g_sig.sigquit)
			exit(g_sig.exit_status);
		else
			exit(EXIT_SUCCESS);
	}
	else
		waitpid(g_sig.pid, &st->code, 0);
	if (st->code > 255)
		g_sig.exit_status = WEXITSTATUS(st->code);
}

static void	reset_fds(t_state *st)
{
	reset_std(st);
	close_fds(st);
	init_fds(&st);
}

static void	default_exec(t_state *st, t_env **env_lst, t_cmd *cmd_lst,
																	char *cmd)
{
	enum e_builtin	ret;

	(void)cmd;
	ret = is_builtin(*cmd_lst->args);
	if (ret)
		exec_builtin(ret, st, env_lst, cmd_lst);
	else if (*cmd_lst->args && filepath_exists(*env_lst, cmd_lst))
		exec_cmd(st, cmd_lst->args);
}

void		cmd_handler(t_state *st, t_env **env_lst, t_cmd *cmd_lst)
{
	char			*cmd;

	sig_init();
	while (cmd_lst && *cmd_lst->args && g_sig.sigint == 0)
	{
		if (check_pipe(cmd_lst))
			has_piped_cmd(st, *env_lst, cmd_lst);
		else
		{
			parse_redirection(st, cmd_lst);
			if (g_sig.exit_status != 1)
			{
				cmd = *cmd_lst->args;
				default_exec(st, env_lst, cmd_lst, cmd);
			}
		}
		cmd_lst = cmd_lst->next;
		reset_fds(st);
		if (cmd_lst != NULL && g_sig.sigint == 0)
			sig_init();
	}
}
