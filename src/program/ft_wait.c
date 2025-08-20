/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:33:15 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/20 15:34:40 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wait(t_pipex_data *pipex)
{
	int	status1;
	int	status2;

	waitpid(pipex->pid1, &status1, 0);
	waitpid(pipex->pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	else
		return (EXIT_FAILURE);
}
