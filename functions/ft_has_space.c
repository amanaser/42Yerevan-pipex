/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:06:25 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:06:27 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_has_space(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}
