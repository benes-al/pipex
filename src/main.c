/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 16:41:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	pipex;
	int				pipefd[2];

	if (argc != 5)
		ft_logic_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	init_struct(&pipex);
	pipex.envp = envp;
	pipex.all_paths = get_all_paths(&pipex);
	if (pipe(pipefd) == -1)
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
	return (ft_wait(&pipex));
}
