/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:19:56 by sehwjang          #+#    #+#             */
/*   Updated: 2024/05/29 17:53:23 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard_bonus.h"

char	*trim_wildcard(char	*word)
{
	char		*ret;
	const int	word_len = ft_strlen(word);
	int			word_idx;
	int			ret_idx;
	bool		flag;

	ret = (char *)ft_malloc(word_len);
	word_idx = -1;
	ret_idx = 0;
	flag = false;
	while (++word_idx < word_len)
	{
		if (word[word_idx] == '*' && flag == true)
			continue ;
		else if (word[word_idx] == '*')
			flag = true;
		else
			flag = false;
		ret[ret_idx++] = word[word_idx];
	}
	ret[ret_idx] = '\0';
	return (ret);
}
