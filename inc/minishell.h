/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:57:57 by nwattana          #+#    #+#             */
/*   Updated: 2023/01/07 15:04:26 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_token
{
	char	*cmd;
}		t_token;

typedef struct s_min
{
	t_token	*token;
	t_list	*env;
}		t_min;

t_token	*get_token(char	*str);

#endif
