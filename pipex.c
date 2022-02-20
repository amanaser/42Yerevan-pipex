/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:04:31 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:04:47 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char **argv, char **env, int f1, int f2)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
		ft_error("Pipe :");
	child1 = fork();
	if (child1 < 0)
		 ft_error("Fork: ");
	if (child1 == 0)
		child_one(f1, end, argv[2], env);
	child2 = fork();
	if (child2 < 0)
		 ft_error("Fork: ");
	if (child2 == 0)
		child_two(f2, end, argv[3], env);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
