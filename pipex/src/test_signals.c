/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:09 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/11/27 20:27:00 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int pipex(int argc, char **argv)
{
	ft_printf("%d ; argv %s \n\n", argc, argv[1]);
	int pid = fork(); 
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			ft_printf("TExt here \n");
			usleep(50000);

		}
	}
	else {
		kill(pid, SIGSTOP);
		sleep(2);
		kill(pid, SIGCONT);
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return(0);

}