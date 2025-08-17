/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_found.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:05:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 23:05:44 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	is_command_empty(char **paths, char **command)
{
	if (!command[0] || !command[0][0])
	{
		ft_free_args(paths);
		ft_free_args(command);
		ft_mimic_sys_error("", ": command not found\n");
		exit(127);
	}
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


char	*is_command_found(char **paths, char **command)
{
	int		i;
	char	*command_path;
	
	i = 0;
	is_command_empty(paths, command);
	while(paths[i])
	{
		command_path = join_command_to_path(paths[i], command[0]);
		if(!command_path)
		{
			ft_free_args(paths);
			ft_free_args(command);	
			ft_sys_error("malloc");
		}
		if (access(command_path, F_OK) == 0)
			return(command_path);	
		free(command_path);
		command_path = NULL;
		i++;
	}
	ft_mimic_sys_error(command[0], ": command not found\n");
	ft_free_args(paths);
	ft_free_args(command);
	exit(127);
	return(NULL);
}
