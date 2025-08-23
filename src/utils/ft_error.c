/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:27:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 11:01:56 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_sys_error(char *arg)
{
	perror(arg);
	exit(EXIT_FAILURE);
}

void	ft_mimic_sys_error(char *error_message, char *arg)
{
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_logic_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}
