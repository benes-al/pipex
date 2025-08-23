/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:32:52 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 12:45:43 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ft_isallspaces(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
		return (0);
	while (argv[i])
	{
		if ((argv[i] < 9 || argv[i] > 13) && argv[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
