/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:10:57 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 13:04:55 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	cal = malloc(size * nmemb);
	if (!cal)
		return (NULL);
	ft_bzero(cal, (nmemb * size));
	return (cal);
}
