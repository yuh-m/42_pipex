/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:03:24 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/04 00:13:26 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_fprint_char(int fd, char chr)
{
	ft_putchar_fd(chr, fd);
	return (1);
}

int	ft_print_char(char chr)
{
	ft_putchar_fd(chr, 1);
	return (1);
}
