/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pipex_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:47:33 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 12:22:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_t_pipex_data(t_pipex_data	*pipex)
{
	pipex->file1 = 0;
	pipex->file2 = 0;
	pipex->pipe_fd[0] = 0;
	pipex->pipe_fd[1] = 0;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->envp = NULL;
	pipex->cmd1.full_command_path = NULL;
	pipex->cmd1.full_command = NULL;
	pipex->cmd2.full_command_path = NULL;
	pipex->cmd2.full_command = NULL;
	pipex->paths = NULL;
}
