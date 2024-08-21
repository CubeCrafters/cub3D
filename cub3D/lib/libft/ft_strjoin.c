/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:21:38 by inryu             #+#    #+#             */
/*   Updated: 2024/08/01 14:19:29 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *dest, char *src)
{
	int		dest_len;
	int		src_len;
	char	*ret;
	int		i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	ret = malloc(dest_len + src_len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		ret[i] = dest[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		ret[dest_len + i] = src[i];
		i++;
	}
	ret[dest_len + src_len] = '\0';
	return (ret);
}
