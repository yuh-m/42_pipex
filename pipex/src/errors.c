/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:09 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/04 14:30:38 by eryudi-m         ###   ########.fr       */
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

int check_input_file(char *file1)
{

}

int	handle_error(void)
{

	return (_ERRNO_H);
}
