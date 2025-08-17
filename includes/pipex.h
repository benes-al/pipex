/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:23:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/17 22:46:11 by benes-al         ###   ########.fr       */
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

bool	is_command_executable(char *path_found);
char	*is_command_found(char **paths, char **command);
void	is_command_valid(char *argv, char **envp);
void	is_file1_valid(char *argv);
void	is_file2_valid(char *argv);
void	parser(char **argv, char **envp);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

void	ft_sys_error(char *error_message);
void	ft_mimic_sys_error(char *command, char *error_message);
void	ft_logic_error(char *error_message);
void	ft_free_args(char **argv);

/******************************************************************************/
/*                               HELPERS                                      */
/******************************************************************************/

void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char *str, char delimiter);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif