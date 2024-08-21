/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:09:44 by inryu             #+#    #+#             */
/*   Updated: 2024/08/01 14:15:38 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *a, int b)
{
	int	i;

	if (!a)
		return (NULL);
	if (!b)
		return (a + ft_strlen(a));
	i = 0;
	while (a[i])
	{
		if (a[i] == b)
			return (a + i);
		i++;
	}
	return (NULL);
}
