/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:26:32 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 20:14:49 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parser(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_parse_error("invalid number of arguments");
	if (!is_file1_valid(argv[1]))
		ft_sys_error("file1");
	if (!is_command_valid(argv[2], envp))
		ft_sys_error("cmd1");
	/* if (!is_command_valid(argv[3], envp))
		ft_sys_error("cmd2"); */
	if (!is_file2_valid(argv[4]))
		ft_sys_error("file2");
}
