/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file1_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:15:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 18:56:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_file1_valid(char *argv)
{
	int	fd_file1;
	
	fd_file1 = open(argv, O_RDONLY);
	if (fd_file1 == -1)
		return (0);
	return (1);
}
