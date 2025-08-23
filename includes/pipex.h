/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:23:46 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/22 12:29:42 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/******************************************************************************/
/*                              INCLUDES                                      */
/******************************************************************************/

# include <unistd.h>	// fork, pipe, dup2, execve, access, close, read, write
# include <fcntl.h>		// open
# include <stdlib.h>	// malloc, free, exit
# include <stdio.h>		// perror
# include <sys/wait.h>	// wait, waitpid
# include <string.h>	// strerror
# include <stdbool.h>	// bool
# include <stdint.h>	// size_t

/******************************************************************************/
/*                               STRUCTS                                      */
/******************************************************************************/

typedef struct s_pipex_data
{
	int			fd_file1;		// File descriptor for the first file
	int			fd_file2;		// File descriptor for the second file
	int			pipe_fd[2];		// File descriptors for the pipe
	pid_t		pid1;			// Process ID for child processes
	pid_t		pid2;			// Process ID for child processes
	char		**envp;			// Environment variables
	char		**all_paths;	// All envp paths
	char		*cmd1_path;		// Full path to the command
	char		*cmd2_path;		// Full path to the command
	char		**cmd1;			// Command and its arguments
	char		**cmd2;			// Command and its arguments
}	t_pipex_data;

/******************************************************************************/
/*                               PROGRAM                                      */
/******************************************************************************/

void	child1_process(char **argv, t_pipex_data *pipex);
void	child2_process(char **argv, t_pipex_data *pipex);
int		ft_wait(int pid1, int pid2);
char	**get_all_paths(t_pipex_data *pipex);
char	*get_cmd_path(t_pipex_data *pipex, char **cmd);
char	**get_cmd(char *argv, t_pipex_data *pipex);
void	parse_and_store_cmd1(char *argv, t_pipex_data *pipex);
void	parse_and_store_cmd2(char *argv, t_pipex_data *pipex);
void	parse_and_open_file1(char *argv, t_pipex_data *pipex);
void	parse_and_open_file2(char *argv, t_pipex_data *pipex);

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

void	ft_sys_error(char *arg);
void	ft_mimic_sys_error(char *arg, char *error_message);
void	ft_logic_error(char *error_message);
void	ft_free_struct(t_pipex_data	*pipex);
void	init_struct(t_pipex_data *pipex);

/******************************************************************************/
/*                               HELPERS                                      */
/******************************************************************************/

void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
bool	ft_isallspaces(char *argv);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char *str, char delimiter);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif