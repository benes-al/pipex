/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:46:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 20:26:47 by benes-al         ###   ########.fr       */
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
		if (ft_strncmp("PATH=", envp[i]) == 0)
		{
			full_path = envp[i] + 5;
			break;
		}
		i++;
	}
	paths = ft_split(full_path, ':');
	return (paths);
}

char	*split_input_command(char *argv)
{
	char **command_args;
	
	command_args = ft_split(argv, ' ');
	if (!command_args || !command_args[0])
		ft_parse_error("no cmd1 provided");
	return (command_args[0]);
}

char	*join_command_to_path(char *path, char *command)
{
	char	*command_path;
	char	*temp;
	
	temp = ft_strjoin(path, "/");
	command_path = ft_strjoin(temp, command);

	#if 1

		printf("%s\n", command_path);

	#endif

	
	return (command_path);
}

bool	is_command_executable(char **paths, char *command)
{
	int	i;
	char *command_path;
	
	i = 0;
	while(paths[i])
	{
		command_path = join_command_to_path(paths[i], command);
		if(access(command_path, X_OK) == 0)
			return (1);
		free(command_path);
		command_path = NULL;
		i++;
	}
	return (0);
}

bool	is_command_valid(char *argv, char **envp)
{
	char	**paths;
	char	*command;
	
	paths = get_paths(envp);
	command = split_input_command(argv);
	if (!is_command_executable(paths, command))
		return (0);
	return (1);
}
