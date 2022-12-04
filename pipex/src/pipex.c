/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryudi-m <eryudi-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:37:31 by eryudi-m          #+#    #+#             */
/*   Updated: 2022/12/04 14:30:38 by eryudi-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
int get_path(envp)
{
	
}
*/
static char* get_path(char **envp)
{
	size_t	i;
	char	**paths;
	char	**trim_path;

	i = 0;
	while (ft_strncmp([envp[i], "PATH=", 5]))
		i++;
	trim_path = ft_substr(env[i], 5, ft_strlen(envp[i]));
	paths = ft_split(trim_path, ';');
	free(trim_path);
	return (paths);

}

int	pipex(int argc,char **argv,  char **envp)
{
	char	*path_env;

	ft_printf("argc %d || argv[0] %s || envp[0] %s \n",argc, argv[0], envp[0]);
	check_argc(argc);
	if(access(argv[1], F_OK | R_OK) != -1)
	{
		path_env = get_path(envp)

	}
	else
		ft_fprintf(STDERR_FILENO,"pipex: %s: %s\n", argv[1], strerror(errno));
	return (0);
}