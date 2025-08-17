/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:56:06 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 18:00:01 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}
