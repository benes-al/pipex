/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:47:33 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:05:00 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex_data *pipex)
{
	pipex->fd_file1 = -1;
	pipex->fd_file2 = -1;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->envp = NULL;
	pipex->all_paths = NULL;
	pipex->cmd1_path = NULL;
	pipex->cmd2_path = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}
