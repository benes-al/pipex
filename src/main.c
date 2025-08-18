/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:43:14 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	pipex;
	//int	pipefd[2];
	
	if (argc != 5)
	ft_logic_error("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	/* if(pipe(pipefd) == -1)
	ft_sys_error */
	init_struct(&pipex);
	pipex.envp = envp;
	parser(argv, &pipex);
	write(1, "great\n", 6);
	ft_free_struct(&pipex);
	return(0);
}
