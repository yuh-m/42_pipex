/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal_communicate_process.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:07:57 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/01 03:09:01 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int pipex(int argc, char * argv[])
{
	ft_printf("%d ; argv %s \n\n", argc, argv[1]);
	return (0);

	int pid = fork();

}