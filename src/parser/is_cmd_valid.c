/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:46:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:44:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	is_cmd_valid(char *argv, t_pipex_data *pipex, int cmd_index)
{
	if (cmd_index == 2)
	{
		pipex->cmd1 = get_cmd(argv, pipex);
		pipex->cmd1_path = get_cmd_path(pipex, pipex->cmd1);
		if (access(pipex->cmd1_path, X_OK) == -1)
		{
			ft_mimic_sys_error(pipex->cmd1[0], ": permission denied\n");
			ft_free_struct(pipex);
			exit(126);
		}
	}
	else if (cmd_index == 3)
	{
		pipex->cmd2 = get_cmd(argv, pipex);
		pipex->cmd2_path = get_cmd_path(pipex, pipex->cmd2);
		if (access(pipex->cmd1_path, X_OK) == -1)
		{
			ft_mimic_sys_error(pipex->cmd2[0], ": permission denied\n");
			ft_free_struct(pipex);
			exit(126);
		}
	}
}
