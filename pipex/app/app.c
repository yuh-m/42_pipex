/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:54:34 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/03 22:22:27 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int a;
	a = pipex(argc, argv, envp);

/*
	ft_printf("error - %d \n", a);
	int n = 0;

	while (envp[n] != NULL) {
	printf("envp[%d]: <%s\n", n, envp[n]);
	n++;
	}
*/

	
	return (0);
}
