/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:00:02 by nwattana          #+#    #+#             */
/*   Updated: 2023/01/07 17:26:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(void)
{
	char	*input;
	t_min	min;


	// keep env in linked list
	while (1)
	{
		input = readline("Enter your command: ");
		min.token = get_token(input);
		if (input == NULL)
			return (0);
		free(input);
  }
}

// handle \' \" 
// handle $
// "$""PTD" -> $PTD , "$PTD" -> value of PTD , $"PTD"->$PTD
// $PTD -> value of PTD

// handle > >> < << |

// dq -> double qoute
// sq -> sigle qoute
typedef	struct s_qoute
{
	int	sq;
	int	dq;
}		t_qoute;

void	qoute_init(t_qoute *tq);

t_token	*get_token(char	*str)
{
	t_qoute qsta;
	char	*tok;
	int		i;

	// clear qouting
	i = 0;
	tok = ft_calloc(1, ft_strlen(str) + 1);
	qoute_init(&qsta);
	while (*str)
	{
		if (*str == '\"')
		{
			if (!qsta.dq)
				qsta.dq = qsta.sq + 1;
			else
				qsta.dq = 0;
		}
		if (*str == '\'')
		{	
			if (!qsta.sq)
				qsta.sq = qsta.dq + 1;
			else
				qsta.sq = 0;
		}
		if (!ft_strchr("\'\"", *str))
		{
			tok[i] = *str;
			i++;
		}
		str++;
	}
	if (qsta.dq != 0 || qsta.sq != 0)
	{
		ft_putstr_fd("qoute not complte close\n", 2);
		free(tok);
		return (NULL);
	}
	printf("result is |%s|\n" , tok);
	free(tok);
	return (NULL);
}

void	tq_dq(t_qoute *tq)
{
	if (tq->dq == 0)
	{
		tq->dq = tq->sq + 1;
	}
	else
	{
		tq->dq = 0;
	}
}

void	qoute_init(t_qoute *tq)
{
	tq->sq = 0;
	tq->dq = 0;
}
