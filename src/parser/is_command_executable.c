/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_executable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:01:11 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 21:39:41 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

bool	is_command_executable(char *path_found)
{
	if (access(path_found, X_OK) == 0)
	{
		free(path_found);	
		return (1);
	}
	free(path_found);
	return(0);
}
