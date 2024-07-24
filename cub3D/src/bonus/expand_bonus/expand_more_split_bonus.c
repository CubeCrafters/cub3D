/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_more_split_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:15:04 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/03 12:58:15 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expand_bonus.h"

static bool	_check_split_word(t_list *token, char ***result)
{
	char	**split;

	if (ft_strchr(((t_token *)token->content)->word, ' ') == NULL)
		return (false);
	split = ft_split(((t_token *)token->content)->word, ' ');
	free(((t_token *)token->content)->word);
	((t_token *)token->content)->word = split[0];
	if (split[1] == NULL)
	{
		free(split);
		return (false);
	}
	*result = split;
	return (true);
}

int	more_split(t_list *token)
{
	t_list	*orgnext;
	t_list	*curr;
	char	**split;
	int		i;

	if (_check_split_word(token, &split) == false)
		return (0);
	orgnext = token->next;
	curr = token;
	i = 1;
	while (split[i + 1] != NULL)
	{
		curr->next = ft_lstnew(new_token(ft_strdup(""), undefined));
		curr->next->next = ft_lstnew(new_token(split[i], word));
		curr = curr->next->next;
		i++;
	}
	curr->next = ft_lstnew(new_token(ft_strdup(""), undefined));
	curr->next->next = ft_lstnew(new_token(split[i], word));
	curr->next->next->next = orgnext;
	free(split);
	return (i + 1);
}
