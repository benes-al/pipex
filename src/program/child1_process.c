/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:44 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 10:24:51 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, t_pipex_data *pipex)
{
	parse_and_open_file1(argv[1], pipex);
	close(pipex->pipe_fd[0]);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[1]);
	dup2(pipex->fd_file1, STDIN_FILENO);
	close(pipex->fd_file1);
	parse_and_store_cmd1(argv[2], pipex);
	if (execve(pipex->cmd1_path, pipex->cmd1, pipex->envp) == -1)
	{
		ft_free_struct(pipex);
		ft_sys_error("execv");
	}
}
