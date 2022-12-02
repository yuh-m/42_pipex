/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:08:26 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/01 03:25:18 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/pipex.h"

int pipex(int argc, char * argv[])
{
	ft_printf("%d ; argv %s \n\n", argc, argv[1]);

	int fd[2];
	if (pipe(fd) == -1)
	{
		return (1);
	}
	int pid1 = fork();
	if (pid1 < 0)
	{
		return(2);
	}
	if (pid1 == 0)
	{
		//child process will run first command
		dup2(fd[1], STDOUT_FILENO); //take first fd and duplicates in fd2 - creates a new fd 
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-la", NULL);
	}

	int pid2 = fork();
	if (pid2 < 0)
	{
		return(3);
	}
	if (pid2 == 0){
		//2nd child process
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep","grep","src",NULL);
	}
	
	close(fd[0]);
	close(fd[1]);
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	
	return (0);

}