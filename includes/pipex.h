/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:23:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/14 19:06:26 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/******************************************************************************/
/*                              INCLUDES                                      */
/******************************************************************************/

#include <unistd.h>		// fork, pipe, dup2, execve, access, close, read, write
#include <fcntl.h>		// open
#include <stdlib.h>     // malloc, free, exit
#include <stdio.h>      // perror
#include <sys/wait.h>   // wait, waitpid
#include <string.h>     // strerror
#include <stdbool.h>	// bool
#include <stdint.h>		// size_t

/******************************************************************************/
/*                               STRUCTS                                      */
/******************************************************************************/

/******************************************************************************/
/*                               PARSER                                       */
/******************************************************************************/

void	parser(int argc, char **argv, char **envp);
bool	is_file1_valid(char *argv);
bool	is_file2_valid(char *argv);
bool	is_command_valid(char *argv, char **envp);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

char	**ft_split(char *str, char delimiter);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2);
void	ft_putstr_fd(char *str);
void	ft_sys_error(char *error_message);
void	ft_parse_error(char *error_message);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t len);

#endif