/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:40 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 22:08:51 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_process(char **argv, t_pipex_data *pipex)
{
	close(pipex->pipe_fd[1]);
	parse_and_open_file2(argv[4], pipex);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	dup2(pipex->fd_file2, STDOUT_FILENO);
	close(pipex->fd_file2);
	parse_and_store_cmd2(argv[3], pipex);
	if (execve(pipex->cmd2_path, pipex->cmd2, pipex->envp) == -1)
	{
		ft_free_struct(pipex);
		ft_sys_error("execv");
	}
}
