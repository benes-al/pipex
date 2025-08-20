/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_file2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:15:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 21:15:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_and_open_file2(char *argv, t_pipex_data *pipex)
{
	int	fd_file2;

	fd_file2 = open(argv, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd_file2 == -1)
	{
		ft_free_struct(pipex);
		ft_sys_error(argv);
	}
	pipex->fd_file2 = fd_file2;
}
