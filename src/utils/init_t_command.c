/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:56:41 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 12:04:04 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_t_command(t_command *cmd)
{
	cmd->full_command_path = NULL;
	cmd->full_command = NULL;
}
