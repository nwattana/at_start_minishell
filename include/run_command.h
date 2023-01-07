/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:34:49 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/31 03:28:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_COMMAND_H
# define RUN_COMMAND_H
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef	struct	s_q
{
	t_list	*front;
	t_list	*rare;
}		t_q;

#endif
