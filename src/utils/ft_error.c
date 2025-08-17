/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:27:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 22:50:20 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_sys_error(char *error_message)
{
	perror(error_message);
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
