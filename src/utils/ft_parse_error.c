/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:19:27 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 12:22:40 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_parse_error(char *error_message)
{
	ft_putstr_fd(error_message);
	exit(EXIT_FAILURE);
}