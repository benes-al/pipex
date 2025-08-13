/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:15:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/13 22:07:46 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_valid(char **argv)
{
	int	fd_file1;
	//int	fd_file2;
	
	fd_file1 = open(argv[1], O_RDONLY);
	if (fd_file1 < 0)
		ft_error("file1:\n");
	return (0);
}