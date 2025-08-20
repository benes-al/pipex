/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_store_cmd1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:46:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 21:15:26 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_and_store_cmd1(char *argv, t_pipex_data *pipex)
{
	pipex->cmd1 = get_cmd(argv, pipex);
	pipex->cmd1_path = get_cmd_path(pipex, pipex->cmd1);
	if (access(pipex->cmd1_path, X_OK) == -1)
	{
		ft_mimic_sys_error(pipex->cmd1[0], ": permission denied\n");
		ft_free_struct(pipex);
		exit(126);
	}
}
