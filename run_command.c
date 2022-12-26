/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:33:19 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/27 02:57:48 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_command.h"

int	main(int ac, char **av, char **env)
{
	int		i = 0;
	char	*path;
	char	**sys_path;

	path = NULL;
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH", ft_strlen(env[i]));
		i++;
	}
	if (!path)
		return (0);
	path = path + 5;
	sys_path = ft_split(path, ':');
	if (!sys_path)
		return (0);
	i = 0;
	while (sys_path[i])
	{
		sys_path[i] = ft_strappend(sys_path[i], "/");
		printf("sys_path = %s\n", sys_path[i]);
		i++;
	}
}
