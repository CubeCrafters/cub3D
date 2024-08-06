/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:23:28 by inryu             #+#    #+#             */
/*   Updated: 2024/08/06 09:53:25 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	cd_iscolor(int c)
{
	if (0 <= c && c <= 255)
		return (1);
	return (0);
}

void	free_strings(char **d)
{
	int	i;

	if (!d)
		return ;
	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
