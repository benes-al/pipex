/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:05:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 12:04:03 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	is_cmd_empty(t_pipex_data *pipex, char **cmd)
{
	if (!cmd[0] || !cmd[0][0])
	{
		ft_free_struct(pipex);
		ft_mimic_sys_error("permission denied:", "");
		exit(126);
	}
}

char	*join_cmd_to_path(char *path, char *cmd_name)
{
	char	*cmd_path;
	char	*temp;

	temp = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(temp, cmd_name);
	free(temp);
	return (cmd_path);
}

char	*get_cmd_path(t_pipex_data *pipex, char **cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	is_cmd_empty(pipex, cmd);
	while (pipex->all_paths[i])
	{
		cmd_path = join_cmd_to_path(pipex->all_paths[i], cmd[0]);
		if (!cmd_path)
		{
			ft_free_struct(pipex);
			ft_sys_error("malloc");
		}
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_mimic_sys_error("command not found: ", cmd[0]);
	ft_free_struct(pipex);
	exit(127);
	return (NULL);
}
