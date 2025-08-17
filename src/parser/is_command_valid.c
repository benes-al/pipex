/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:46:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 00:23:22 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_all(char **paths, char **command)
{
	ft_free_args(paths);
	ft_free_args(command);		
}

char	**get_paths(char **envp)
{
	int	i;
	char *full_path;
	char **paths;
	
	i = 0;
	full_path = NULL;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			full_path = envp[i] + 5;
			break;
		}
		i++;
	}
	if (!full_path)
		ft_logic_error("PATH variable not found\n");
	paths = ft_split(full_path, ':');
	if (!paths)	
		ft_sys_error("malloc");
	return (paths);
}

char	**get_command(char *argv, char **paths)
{
	char **command;
	
	command = ft_split(argv, ' ');
	if (!command)
	{
		ft_free_args(paths);
		ft_sys_error("malloc");
	}
	return (command);
}

void	is_command_valid(char *argv, char **envp)
{
	char	**paths;
	char	**command;
	char	*path_found;
	
	paths = get_paths(envp);
	command = get_command(argv, paths);
	path_found = is_command_found(paths, command);
	if (!is_command_executable(path_found))
	{
		ft_mimic_sys_error(command[0], ": permission denied\n");
		ft_free_all(paths, command);
		exit(126);
	}
	ft_free_all(paths, command);
}
