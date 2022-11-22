/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:12:55 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:45 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_len_unsigned(unsigned int number)
{
	size_t	len;

	len = 0;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	len++;
	return ((int) len);
}
