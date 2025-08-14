/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file2_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:15:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 18:56:14 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_file2_valid(char *argv)
{
	int	fd_file2;
	
	fd_file2 = open(argv, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd_file2 == -1)
		return(0);
	return (1);
}
