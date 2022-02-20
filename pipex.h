/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:05:05 by amanaser          #+#    #+#             */
/*   Updated: 2021/10/30 19:05:07 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define EXIT_FAILURE

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

char			**ft_split(char const *s, char c);
int				ft_strncmp(const char *s1, const char *s2, int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_pipex(char **argv, char **env, int f1, int f2);
size_t			ft_strlen(const char *s);
char			*parse_cmd(char *cmd, char **env, int *to_free);
void			child_one(int f1, int fd[2], char *cmd1, char **env);
void			child_two(int f2, int fd[2], char *cmd2, char **env);
void			perror(const char *prefix);
int				ft_has_space(char *str);
void			ft_error(char *str);
void			ft_free_str(char **str);

#endif
