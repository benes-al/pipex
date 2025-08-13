/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:19:32 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/13 20:26:35 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	envp(int argc, char **argv, char **envp)
{
	int	i;
	char *PATH;
	char **PATHS;
	
	PATH = NULL;
	PATHS = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i]) == 0)
			PATH = envp[i] + 5;
		i++;
	}
	PATHS = ft_split(PATH, ':');
	i = 0;
	while (PATHS[i])
	{
		printf("%s\n", PATHS[i]);
		i++;
	}
}