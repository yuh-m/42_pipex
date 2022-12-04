/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/03 18:34:24 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
int get_path(envp)
{
	
}
*/

int	pipex(int argc,char **argv,  char **envp)
{
	ft_printf("argc %d || argv[0] %s || envp[0] %s \n",argc, argv[0], envp[0]);
	check_argc(argc);
	if(access(argv[1], F_OK | R_OK) != -1)
		ft_printf("file found\n");
	else
	{
		ft_printf("file_not_found\n");
		//ft_printf("pipex: %s: %s \n", argv[1], strerror(errno));
		ft_printf("pipex: %s: %s || %d ||%s \n", argv[1], strerror(errno), __LINE__, __FILE__ ); // it should'n be on log but on stderror instead
		//ft_putstr_fd(__LINE__, STDERR_FILENO);
		
	}	
	return (0);
}