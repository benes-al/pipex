/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:56:51 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 17:25:14 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_args(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free_struct(t_pipex_data	*pipex)
{
	if (pipex->fd_file1 != -1)
		close(pipex->fd_file1);
	if (pipex->fd_file2 != -1)
		close(pipex->fd_file2);
	if (pipex->pipe_fd[0] != -1)
		close(pipex->pipe_fd[0]);
	if (pipex->pipe_fd[1] != -1)
		close(pipex->pipe_fd[1]);
	if (pipex->all_paths)
		ft_free_args(pipex->all_paths);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
	if (pipex->cmd1)
		ft_free_args(pipex->cmd1);
	if (pipex->cmd2)
		ft_free_args(pipex->cmd2);
}
