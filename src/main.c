/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 15:16:24 by benes-al         ###   ########.fr       */
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
	is_cmd_valid(argv[2], pipex, 2);
	if (execv(pipex->cmd1_path, pipex->cmd1) == -1)
	{
		ft_sys_error("execv");
		ft_free_struct(pipex);
	}
}

void	child2_process(char **argv, t_pipex_data *pipex)
{
	close(pipex->pipe_fd[1]);
	is_file2_valid(argv[4], pipex);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	dup2(pipex->fd_file2, STDOUT_FILENO);
	close(pipex->fd_file2);
	is_cmd_valid(argv[3], pipex, 3);
	if (execv(pipex->cmd2_path, pipex->cmd2) == -1)
	{
		ft_sys_error("execv");
		ft_free_struct(pipex);
	}
}
int	ft_wait(t_pipex_data *pipex)
{
	int	status1;
	int	status2;

	waitpid(pipex->pid1, &status1, 0);
	waitpid(pipex->pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else
		return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	pipex;
	int	pipefd[2];
	
	if (argc != 5)
		ft_logic_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	init_struct(&pipex);
	pipex.envp = envp;
	pipex.all_paths = get_all_paths(&pipex);
	if(pipe(pipefd) == -1)
		ft_sys_error("pipe");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		perror("fork");
	else if (pipex.pid1 == 0)
		child1_process(argv, &pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		perror("fork");
	else if (pipex.pid2 == 0)
		child2_process(argv, &pipex);
	ft_free_struct(&pipex);
	return(ft_wait(&pipex));
}
