/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/09 19:41:39 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**get_cmd_args(char *args)
{
	char	**arg;

	arg = ft_split(args, ' ');
	return (arg);
}

char	*get_cmd(char **path_env, char *cmd)
{
	char	*aux;
	char	*command;

	while (*path_env)
	{
		aux = ft_strjoin(*path_env, "/");
		command = ft_strjoin(aux, cmd);
		free(aux);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path_env++;
	}
	return (E_INV_CMD);
}

void	first_process(t_data data)
{
	dup2(data.pipe_fd[1], STDOUT_FILENO);
	close(data.pipe_fd[0]);
	dup2(data.fd_in, STDIN_FILENO);
	data.cmd_args = get_cmd_args(data.argv[2]);
	data.cmd = get_cmd(data.path_env, data.cmd_args[0]);
	if (ft_strncmp(data.cmd, E_INV_CMD, ft_strlen(data.cmd)) == 0)
	{
		ft_fprintf(STDERR_FILENO, "%s: command not found \n", data.cmd_args[0]);
		free_child_pd(&data);
		free_data(&data);
		exit(errno);
	}
	execve(data.cmd, data.cmd_args, data.path_env);
}

void	second_process(t_data data)
{
	dup2(data.pipe_fd[0], STDIN_FILENO);
	close(data.pipe_fd[1]);
	dup2(data.fd_out, STDOUT_FILENO);
	data.cmd_args = get_cmd_args(data.argv[3]);
	data.cmd = get_cmd(data.path_env, data.cmd_args[0]);
	if (ft_strncmp(data.cmd, E_INV_CMD, ft_strlen(data.cmd)) == 0)
	{
		ft_fprintf(STDERR_FILENO, "%s: command not found \n", data.cmd_args[0]);
		free_child_pd(&data);
		free_data(&data);
		exit(errno);
	}
	execve(data.cmd, data.cmd_args, data.path_env);
}
