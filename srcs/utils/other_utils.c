/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:28:04 by jonny             #+#    #+#             */
/*   Updated: 2021/01/31 17:05:09 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**free_2darray(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free((void*)tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	handle_signal(int signum)
{
	signal(signum, SIG_IGN);
}