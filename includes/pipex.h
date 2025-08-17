/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:23:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 12:03:03 by benes-al         ###   ########.fr       */
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

typedef struct s_command
{
	char	*full_command_path;	// Full path to the command (/usr/bin/ls)
	char	**full_command;		// Command and its arguments ({"ls", "-l", NULL})
}	t_command;

typedef struct s_pipex_data
{
	int			file1;			// File descriptor for the first file
	int			file2;			// File descriptor for the second file
	int			pipe_fd[2];		// File descriptors for the pipe
	pid_t		pid1;			// Process ID for child processes
	pid_t		pid2;			// Process ID for child processes
	char		**envp;			// Environment variables
	t_command 	cmd1;			// Struckt with command and its full path
	t_command 	cmd2;			// Struckt with command and its full path
	char		**paths;		// split paths for execv()
}	t_pipex_data;

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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *str);
void	ft_sys_error(char *error_message);
void	ft_parse_error(char *error_message);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t len);
void	ft_free_args(char **argv);

#endif