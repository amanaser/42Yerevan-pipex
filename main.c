/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:05:15 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:05:17 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	f1;
	int	f2;

	if (argc != 5)
		ft_error("Arguments: ");
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (access(argv[1], R_OK | F_OK) == -1)
		ft_error("File1 :");
	if (f1 < 0 || f2 < 0)
		ft_error("file");
	if (dup2(f1, 0) == -1 || dup2(f2, 1) == -1)
		ft_error("Dup2 :");
	ft_pipex(argv, env, f1, f2);
	return (0);
}
