/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:05:24 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:05:28 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int f1, int end[2], char *cmd1, char **env)
{
	int		to_free;
	char	*tmp;
	char	**cmd;

	tmp = parse_cmd(cmd1, env, &to_free);
	cmd = ft_split(tmp, ' ');
	if (to_free)
		free(tmp);
	close(end[0]);
	if (dup2(end[1], 1) < 0)
		ft_error("dup2 failed");
	close(end[1]);
	close(f1);
	execve(cmd[0], cmd, env);
	ft_free_str(cmd);
}

void	child_two(int f2, int end[2], char *cmd2, char **env)
{
	int		to_free;
	char	*tmp;
	char	**cmd;

	tmp = parse_cmd(cmd2, env, &to_free);
	cmd = ft_split(tmp, ' ');
	if (to_free)
		free(tmp);
	close(end[1]);
	if (dup2(end[0], 0) < 0)
		ft_error("dup2 failed");
	close(end[0]);
	close(f2);
	execve(cmd[0], cmd, env);
	ft_free_str(cmd);
}
