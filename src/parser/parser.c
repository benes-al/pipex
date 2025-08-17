/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:26:32 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 19:02:26 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parser(char **argv, char **envp)
{
	is_file2_valid(argv[4]);
	is_file1_valid(argv[1]);
	is_command_valid(argv[2], envp);
	is_command_valid(argv[3], envp);
}
