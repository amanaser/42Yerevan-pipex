/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:04:06 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:04:12 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*g_tmp;
char	*g_cut;
char	**g_paths;

static char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	paths = ft_split(env[i], ':');
	return (paths);
}

static char	*join_cmd(char *addr, char *cmd)
{
	char	*tmp;
	char	*done;

	tmp = ft_strjoin(addr, "/");
	done = ft_strjoin(tmp, cmd);
	free(tmp);
	return (done);
}

static char	*split_cmd(char *str)
{
	char	*rtn;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!ft_has_space(str))
		return (str);
	while (str[len] != ' ')
		len++;
	rtn = (char *)malloc(i + 1);
	while (i < len)
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*parse_cmd(char *cmd, char **env, int *to_free)
{
	int		i;

	i = -1;
	if (*cmd == '/')
		*to_free = 0;
	else
		*to_free = 1;
	if (*cmd == '/' && access(cmd, F_OK) == 0)
		return (cmd);
	else
	{
		g_paths = get_paths(env);
		g_cut = split_cmd(cmd);
		if (ft_strlen(g_cut) == 0)
			ft_error("CMD ։");
		while (g_paths[++i] != '\0')
		{
			g_tmp = join_cmd(g_paths[i], g_cut);
			if (access(g_tmp, F_OK) == 0)
				return (join_cmd(g_paths[i], cmd));
			free(g_tmp);
		}
	}
	ft_error("CMD :");
	return (NULL);
}
