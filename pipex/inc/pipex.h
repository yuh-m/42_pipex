/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:03:57 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/03 03:29:27 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h> //open, read,
#include <unistd.h> //execl
#include <stdlib.h>
#include <stdio.h>
#include <errno.h> //perror
#include <sys/wait.h> //wait
#include <signal.h>
#include "libft.h"

#define READ 0
#define WRITE 1
//#define

int	pipex(int argc, char **argv, char **envp);
int err_argument_number(void);
#endif
