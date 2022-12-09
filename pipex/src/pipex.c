/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/09 16:28:17 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
int get_path(envp)
{
	
}


static int is_backslash(char str)
{
	return (str == '\'');
}

char **parse_cmd(char *argv_cmd)
{
	//if contains backslash
	if (con)
	while (*argv_cmd)
	{
		if (is_backslash(argv_cmd) == 1)
			return(1);
		argv_cmd++;
	}
	return (0);
}
*/

static char** get_cmd_args(char *args)
{
	char **arg;
	
	arg = ft_split(args, ' ');
	return (arg);
}

static char* get_cmd (char **path_env, char *cmd)
{
	char	*aux;
	char	*command;

	while (*path_env)
	{
		aux = ft_strjoin(*path_env, "/");
		command = ft_strjoin(aux, cmd);
		free(aux);
		if(access(command, 0) == 0)
			return(command);
		free(command);
		path_env++;
	}
	return (E_INV_CMD);
}

static char** get_env_paths(char **envp)
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

/*
static char *path_env_string(char **envp)
{
	while (ft_strncmp("PATH=",*envp, 5))
		envp++;
	return (*envp + 5);
}
*/

static void init_data(t_data *data, int argc, char **argv, char **envp)
{
		data->argc = argc;
		data->argv = argv;
		data->envp = envp;
		data->path_env = get_env_paths(envp);
		//data->cmd_args = data->path_env;
		//data->path_env_string = path_env_string(envp);
		//data->cmd_path = ft_split(data->path_env_string, ':');
		
}

int	pipex(int argc,char **argv,  char **envp)
{
	t_data	data;
	int		id_status;

	//ft_printf("argc %d || argv[0] %s || envp[0] %s \n",argc, argv[0], envp[0]);
	check_argc(argc);
	init_data(&data, argc, argv, envp);
	data.fd_in = file_open(argv[1], READ);
	data.fd_out = file_open(argv[4], WRITE);
	check_access(data);
	data.pipe = pipe(data.pipe_fd);
	data.pid1 = fork();

	if (data.pid1 == 0)
	{
		dup2(data.pipe_fd[1], STDOUT_FILENO);
		close(data.pipe_fd[0]);
		dup2(data.fd_in,STDIN_FILENO);
		data.cmd_args = get_cmd_args(argv[2]);
		data.cmd = get_cmd(data.path_env, data.cmd_args[0]);
		/*
		if (ft_strncmp(data.cmd, E_INV_CMD, ft_strlen(data.cmd)) == 0)
		{
			free_child_pd(&data);
			free_data(&data);
			perror(E_INV_CMD);
			exit(127);
		}
		printf("HEELLOOO");
		*/
		execve(data.cmd, data.cmd_args, data.path_env);	
	}
	data.pid2 = fork();
	if (data.pid2 == 0)
	{
		dup2(data.pipe_fd[0], STDIN_FILENO);
		close(data.pipe_fd[1]);
		dup2(data.fd_out, STDOUT_FILENO);
		data.cmd_args = get_cmd_args(argv[3]);
		data.cmd = get_cmd(data.path_env, data.cmd_args[0]);
		execve(data.cmd, data.cmd_args, data.path_env);
		//ft_printf(" \n 2nd process\n");
	}
	close_pipes_fd(&data);
	waitpid(data.pid1, &id_status, 0);
	waitpid(data.pid2, &id_status, 0);
	free_data(&data);
	return (WEXITSTATUS(id_status));
}