/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:26:32 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:25:22 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parser(char **argv, t_pipex_data *pipex)
{
	is_file2_valid(argv[4], pipex);
	is_file1_valid(argv[1], pipex);
	pipex->all_paths = get_all_paths(pipex);
	is_cmd_valid(argv[2], pipex, 2);
	is_cmd_valid(argv[3], pipex, 3);
}
