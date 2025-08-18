/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:28:05 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/18 17:12:52 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_wrdcnt(char *str, char sep)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			wrd++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (wrd);
}

static char	*ft_genwrd(char *str, char sep)
{
	char	*new_s;
	int		len;

	len = 0;
	while (str[len] != sep && str[len])
		len++;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	len = 0;
	while (str[len] != sep && str[len])
	{
		new_s[len] = str[len];
		len++;
	}
	new_s[len] = '\0';
	return (new_s);
}

static char	**ft_free(char **strs, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(strs[n]);
		n++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char *str, char delimiter)
{
	char	**strs;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_wrdcnt(str, delimiter) + 1));
	if (!strs)
		return (NULL);
	while (++i < ft_wrdcnt(str, delimiter))
	{
		while (str[j] == delimiter && str[j])
			j++;
		strs[i] = ft_genwrd(&str[j], delimiter);
		if (!strs[i])
			return (ft_free(strs, i));
		while (str[j] != delimiter && str[j])
			j++;
	}
	strs[i] = 0;
	return (strs);
}
