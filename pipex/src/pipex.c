/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/11/27 19:36:56 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int pipex(int argc, char **argv)
{
	// int id = fork();
	ft_printf("%d ; argv %s \n\n", argc, argv[1]);
	// ft_printf("%d \n", id );
	int p1[2];
	int p2[2];
	// int pid;
	// int x = 2;

	if (pipe(p1) == -1 || pipe(p2) == -1)
		return (1);
	int pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int x = 2;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return (3);
		ft_printf("1C = Received %d \n", x);
		x *= 4; // same as x = x*4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		ft_printf("1C = Wrote %d \n", x);
		close(p1[1]); // it wont wirt
		close(p2[0]);
	}
	else
	{
		close(p1[1]); // it wont wirt
		close(p2[0]); // it wont read
		int y = 2;
		y = y * 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return (5);
		ft_printf("2P = Wrote %d \n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		ft_printf("2P = Result is %d \n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	close(p1[0]);
	close(p1[1]);
	return (0);
}
