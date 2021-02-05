/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:28:04 by jonny             #+#    #+#             */
/*   Updated: 2021/02/05 16:18:18 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**free_2darray(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free((void*)tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_all(t_state *status, t_env **env_lst, t_cmd **cmd_lst)
{
	free_env_lst(env_lst);
	free_cmd_lst(cmd_lst);
	free(status);
}
