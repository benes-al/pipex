/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 22:01:40 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	pipex;
	int				pid1;
	int				pid2;

	if (argc != 5)
		ft_logic_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	init_struct(&pipex);
	pipex.envp = envp;
	pipex.all_paths = get_all_paths(&pipex);
	if (pipe(pipex.pipe_fd) == -1)
		ft_sys_error("pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror("fork");
	else if (pid1 == 0)
		child1_process(argv, &pipex);
	pid2 = fork();
	if (pid2 == -1)
		perror("fork");
	else if (pid2 == 0)
		child2_process(argv, &pipex);
	ft_free_struct(&pipex);
	return (ft_wait(pid1, pid2));
}
