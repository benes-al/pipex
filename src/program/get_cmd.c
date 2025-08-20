/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:20:27 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:44:30 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd(char *argv, t_pipex_data *pipex)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		ft_free_struct(pipex);
		ft_sys_error("malloc");
	}
	return (cmd);
}
