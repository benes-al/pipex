/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:27:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/19 14:48:38 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_sys_error(char *command)
{
	perror(command);
	exit(EXIT_FAILURE);
}

void	ft_mimic_sys_error(char *command, char *error_message)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(error_message, 2);
}

void	ft_logic_error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}
