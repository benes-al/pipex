/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:20:27 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 12:46:05 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *argv, t_pipex_data *pipex)
{
	char	**cmd;

	if (ft_isallspaces(argv))
	{
		ft_free_struct(pipex);
		ft_mimic_sys_error("command not found:", "");
		exit(127);
	}
	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		ft_free_struct(pipex);
		ft_sys_error("malloc");
	}
	return (cmd);
}
