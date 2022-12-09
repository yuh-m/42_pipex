/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:03:57 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/08 22:58:49 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h> //open, read,
#include <unistd.h> //execl, access
#include <stdlib.h>
#include <stdio.h>
#include <errno.h> //perror
#include <string.h> //strerror
#include <sys/wait.h> //wait
#include <signal.h>
#include "../inc/libft.h"

#define READ 0
#define WRITE 1

typedef struct s_data
{
	int		argc;
	char 	**argv;
	char 	**envp;
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	char	**path_env;
	char	*path_env_string;
	char	**cmd_args;
	char	*cmd;
	char	**cmd_path;
	int		pipe_fd[2];
	int		pipe;

} t_data;


/** @brief args - file1 cmd1 cmd2 file2
 * @param argc arguments count
 * @param argv arguments vector
 * @param envp enviroment variables
**/
int	pipex(int argc, char **argv, char **envp);

/**
	@brief Check if pipex holds exactly 4 arguments
**/
int check_argc(int argc);

/** @brief open file in read or write mode
 * @param file path of filename
 * @param mode READ (0) else WRITE(1)
 * @return int fd of the opened file
*/
int	file_open(char *file, int mode);



//free.c
int free_data(t_data *data);
int	free_child_pd(t_data *data);
int close_pipes_fd(t_data *data);
#endif
