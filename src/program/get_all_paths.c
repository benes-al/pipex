/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:21:22 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:45:50 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_envp_path(t_pipex_data *pipex)
{
	int		i;
	char	*envp_path;

	i = 0;
	envp_path = NULL;
	while (pipex->envp[i])
	{
		if (ft_strncmp("PATH=", pipex->envp[i], 5) == 0)
		{
			envp_path = pipex->envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!envp_path)
	{
		ft_free_struct(pipex);
		ft_logic_error("PATH variable not found\n");
	}
	return (envp_path);
}

char	**get_all_paths(t_pipex_data *pipex)
{
	char	**all_paths;
	char	*envp_path;

	envp_path = get_envp_path(pipex);
	all_paths = ft_split(envp_path, ':');
	if (!all_paths)
	{
		ft_free_struct(pipex);
		ft_sys_error("malloc");
	}
	return (all_paths);
}
