/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:33:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 22:54:42 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	//int	pipefd[2];

	if (argc != 5)
		ft_logic_error("Usage: ./pipex file1 cmd1 cmd2 file2");
	/* if(pipe(pipefd) == -1)
		ft_sys_error */
	parser(argv, envp);
	write(1, "great\n", 6);
	return(0);
}
