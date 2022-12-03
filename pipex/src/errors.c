/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:04:09 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/03 02:39:54 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int err_argument_number(void)
{
	ft_printf("Exec format error\n \
	Arguments are in this order - file1 cmd1 cmd2 file2 \n");
	return(_ERRNO_H);
}

int err_input_file(void)
{
	return(_ERRNO_H);
}