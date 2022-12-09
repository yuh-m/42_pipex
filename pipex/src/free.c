/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/09 19:39:43 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	free_data(t_data *data)
{
	int	i;

	i = 0;
	close(data->fd_in);
	close(data->fd_out);
	while (data->path_env[i])
	{
		free(data->path_env[i]);
		i++;
	}
	free(data->path_env);
	return (0);
}

int	free_child_pd(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	return (0);
}

int	close_pipes_fd(t_data *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	return (0);
}
