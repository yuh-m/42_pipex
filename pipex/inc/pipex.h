/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:03:57 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/11/27 20:27:00 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h> //open, read,
#include <unistd.h> //execl
#include <stdlib.h>
#include <stdio.h>
#include <errno.h> //perror
#include "libft.h"
#include <sys/wait.h> //wait
#include <signal.h>

//# define STDIN 0
//# define STDOUT 1

int	pipex(int argc, char **argv);

#endif
