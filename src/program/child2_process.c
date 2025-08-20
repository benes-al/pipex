/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:40 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 16:36:33 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_process(char **argv, t_pipex_data *pipex)
{
	close(pipex->pipe_fd[1]);
	is_file2_valid(argv[4], pipex);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	dup2(pipex->fd_file2, STDOUT_FILENO);
	close(pipex->fd_file2);
	is_cmd2_valid(argv[3], pipex);
	if (execv(pipex->cmd2_path, pipex->cmd2) == -1)
	{
		ft_sys_error("execv");
		ft_free_struct(pipex);
	}
}
