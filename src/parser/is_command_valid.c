/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:46:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/16 23:55:46 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_sys_error("PATH not found in envp");
	paths = ft_split(full_path, ':');
	return (paths);
}

void	free_all(char **paths, char **command)
{
	ft_free_args(paths);
	ft_free_args(command);
}

char	*join_command_to_path(char *path, char *command)
{
	char	*command_path;
	char	*temp;
	
	temp = ft_strjoin(path, "/");
	command_path = ft_strjoin(temp, command);
	free(temp);
	return (command_path);
}

bool	is_command_executable(char **paths, char *command)
{
	int		i;
	char	*command_path;
	
	i = 0;
	while(paths[i])
	{
		command_path = join_command_to_path(paths[i], command);
		if(!command_path)
			return (0);
		if (access(command_path, X_OK) == 0)
		{
			free(command_path);	
			return (1);
		}
		free(command_path);
		command_path = NULL;
		i++;
	}
	return (0);
}

bool	is_command_valid(char *argv, char **envp)
{
	char	**paths;
	char	**command;
	
	paths = get_paths(envp);
	if (!paths)	
		ft_sys_error("get_paths");
	command = ft_split(argv, ' ');
	if (!command)
	{
		ft_free_args(paths);
		ft_sys_error("ft_split");
	}
	if (!command[0] || !command[0][0])
	{
		free_all(paths, command);
		ft_parse_error("no command provided or empty");
	}
	if (!is_command_executable(paths, command[0]))
	{
		free_all(paths, command);
		return (0);
	}
	free_all(paths, command);
	return (1);
}
