/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/02 21:46:28 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


int pipex(int argc,char **argv)
{
	ft_printf("argc %d || argv[0]; %s \n",argc, argv[0]);
	if (argc != 5)
		return(err_argument_number());
	if(access(argv[1], F_OK | R_OK) != -1)
		ft_printf("file found\n");
	else
		ft_printf("file_not_found\n");
	
	
	return (0);
}