/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <jonny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:44:25 by josaykos          #+#    #+#             */
/*   Updated: 2021/01/05 15:58:55 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 0 && c <= 255)
	{
		if (c >= 65 && c <= 90)
			return (c += 32);
	}
	else
		return ((unsigned int)c);
	return (c);
}
