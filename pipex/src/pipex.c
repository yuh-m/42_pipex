/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/09 19:38:20 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	**get_env_paths(char **envp)
{
	size_t	i;
	char	**paths;
	char	*trim_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	trim_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(trim_path, ':');
	free(trim_path);
	return (paths);
}

static void	init_data(t_data *data, int argc, char **argv, char **envp)
{
		data->argc = argc;
		data->argv = argv;
		data->envp = envp;
		data->path_env = get_env_paths(envp);
}

int	pipex(int argc, char **argv, char **envp)
{
	t_data	data;
	int		id_status;

	check_argc(argc);
	init_data(&data, argc, argv, envp);
	data.fd_in = file_open(argv[1], READ);
	data.fd_out = file_open(argv[4], WRITE);
	check_access(data);
	data.pipe = pipe(data.pipe_fd);
	data.pid1 = fork();
	if (data.pid1 == 0)
		first_process(data);
	data.pid2 = fork();
	if (data.pid2 == 0)
		second_process(data);
	close_pipes_fd(&data);
	waitpid(data.pid1, &id_status, 0);
	waitpid(data.pid2, &id_status, 0);
	free_data(&data);
	return (WEXITSTATUS(id_status));
}
