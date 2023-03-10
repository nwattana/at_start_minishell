/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:46:12 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/27 02:46:53 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total = len_s1 + len_s2 + 1;
	res = (char *)malloc(total);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, total);
	ft_strlcpy(res + len_s1, s2, total);
	*(res + len_s1 + len_s2) = '\0';
	free(s1);
	return (res);
}
