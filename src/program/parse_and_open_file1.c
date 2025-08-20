/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_file1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:15:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 21:15:32 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_and_open_file1(char *argv, t_pipex_data *pipex)
{
	int	fd_file1;

	fd_file1 = open(argv, O_RDONLY);
	if (fd_file1 == -1)
	{
		ft_free_struct(pipex);
		ft_sys_error(argv);
	}
	pipex->fd_file1 = fd_file1;
}
