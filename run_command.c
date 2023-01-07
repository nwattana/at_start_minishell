/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:33:19 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/31 03:54:55 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_command.h"
char	*get_path(char **env);
char	**clean_path(char **path);
char	**create_arg(void);

int	main(int ac, char **av, char **env)
{
	int		i;
	char	*path;
	char	**sys_path;
	char	*com;
	char	**arg = create_arg();
	int		file1 = open("./test_dup", O_WRONLY | O_CREAT, 0777);

	//path = get_path(env);
	if (path == NULL) 
		return (1);
	path = getenv("PATH");
	sys_path = ft_split(path, ':');
	if (!sys_path)
		return (0);
	sys_path = clean_path(sys_path);



	/* check access */
	char	*cm = "ls";
	i = 0;
	while (sys_path[i])
	{
		com = ft_strjoin(sys_path[i], cm);
		printf("access to -> %s\n", com);
		if (access(com,0) == 0)
		{
			printf("found at %s\n", com);
			break ;
		}
		if (com)
			free(com);
		com = NULL;
		i++;
	}
	printf("run command -> %s", com);
	i = 0;
	while (arg[i])
	{
		printf(" %s",arg[i]);
		i++;
	}
	printf("\n");
	int pid;
	int	ftout = dup(STDOUT_FILENO);
	printf("affter this will push into file\n");
	int file2 = dup2(file1, STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
		execv(com, arg);
	else
	{
		wait(NULL);
		dup2(ftout, file2);
		printf("Program Finish\n");
	}
}


char	**create_arg(void)
{
	char	**res;
	char	*tmp;

	res = malloc(sizeof(char *) * 2);
	tmp = malloc(2);
	tmp[0] = '.';
	tmp[1] = '\0';
	res[0] = tmp;
	res[1] = NULL;
	return (res);
}

char	**clean_path(char **path)
{
	int		i;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strtrim(path[i], " ");
		path[i] = ft_strappend(path[i], "/");
		free(temp);
		i++;
	}
	return (path);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH", ft_strlen(env[i]));
		i++;
	}
	if (!path)
		return (0);
	path = path + 5;
	return (path);
}
