/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:48:24 by jonny             #+#    #+#             */
/*   Updated: 2021/05/04 16:48:29 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

/*
** Move to targeted directory
*/

int	cd(char *arg, t_env *env_lst)
{
	int		errnum;
	int		ret;
	char	*str;
	char	tmp[BUF_SIZE];

	str = arg;
	if (arg && arg[0] == '-')
		str = get_env(env_lst, "OLDPWD");
	if (!arg || arg[0] == '~')
	{
		str = get_env(env_lst, "HOME");
		if (str == NULL || !ft_strlen(str))
			return (EXIT_SUCCESS);
	}
	getcwd(tmp, BUF_SIZE);
	ret = chdir(str);
	errnum = errno;
	export_env(&env_lst, ft_strdup("OLDPWD"), ft_strdup(tmp));
	if (ret == 0)
		return (EXIT_SUCCESS);
	error_cases(errnum, "cd", str);
	return (EXIT_FAILURE);
}
