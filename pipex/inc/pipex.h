/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:03:57 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/04 14:30:38 by eryudi-m         ###   ########.fr       */
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
#endif
