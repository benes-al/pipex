/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:44 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 16:41:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, t_pipex_data *pipex)
{
	close(pipex->pipe_fd[0]);
	is_file1_valid(argv[1], pipex);
	dup2(pipex->fd_file1, STDIN_FILENO);
	close(pipex->fd_file1);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	is_cmd1_valid(argv[2], pipex);
	if (execv(pipex->cmd1_path, pipex->cmd1) == -1)
	{
		ft_sys_error("execv");
		ft_free_struct(pipex);
	}
}
