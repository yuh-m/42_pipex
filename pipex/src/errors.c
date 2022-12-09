/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:09 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/08 22:47:05 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Exec format error\n \
		Arguments are in this order - file1 cmd1 cmd2 file2 \n", STDERR_FILENO);
		exit(1);
	}
	return (0);
}

int check_access(t_data data)
{
	if (data.fd_in == -1)
	{
		int	exit_code;
		
		exit_code = 0;
		if(access(data.argv[1], F_OK & R_OK))
			ft_fprintf(STDERR_FILENO,"pipex: %s: %s\n", data.argv[1], strerror(errno));
		free_data(&data);
		ft_fprintf(STDERR_FILENO,"pipex: %s: %s\n", data.argv[1], strerror(errno));
		exit(exit_code);
	}
	if (data.fd_out == -1)
	{
		free_data(&data);
		ft_fprintf(STDERR_FILENO,"pipex: %s: %s\n", data.argv[4], strerror(errno));
		exit(1);
	}
	return (0);
}

int	handle_error(void)
{

	return (_ERRNO_H);
}
