/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:54:34 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/08 00:56:24 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	file_open(char *file, int mode)
{
	if (mode == READ)
		return (open(file, O_RDONLY, 0644));
	else
		return (open(file, O_TRUNC | O_CREAT | O_RDWR, 0644));
}
