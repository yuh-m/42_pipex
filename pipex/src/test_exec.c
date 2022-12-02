/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:23:21 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/01 03:09:30 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int pipex(int argc, char **argv)
{
	ft_printf("%d ; argv %s \n\n", argc, argv[1]);
	int pid = fork();
	if (pid == -1) 
		return 1;
	if (pid == 0)
	{
		int file = open("pings.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		//int file2 = dup(file); //return a fd - takes the fd from file and create a 
		// new one, pointing to the same place
		int file2 = dup2(file, STDOUT_FILENO); //it will replace the file of STDOUT to the file
		close(file);
		ft_printf("file desc from file2 %d \n",file2);


		int err = execlp("ls","ls","-la", NULL );
		if (err == -1)
		{
			ft_printf("count not find program \n");
			return(3);
		}
	}
	else {
		int wstatus;
		//parent process
		wait(&wstatus);
		if (WIFEXITED(wstatus)) 
		{
			int status_code = WEXITSTATUS(wstatus);
			if(status_code == 0)
				ft_printf("success \n");
			else
				ft_printf("failure - status code: %d \n", status_code);
		}
		printf("AFTER PROCESSING \n");

	}
	return(0);
}