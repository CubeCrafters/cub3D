/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:23:18 by taerankim         #+#    #+#             */
/*   Updated: 2024/06/03 13:18:00 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expand_bonus.h"
#include "wildcard_bonus.h"

static t_quote	_is_quote(t_token *token)
{
	const int	len = ft_strlen(token->word);

	if (len < 2)
		return (q_not);
	if (token->word[0] == '\'' \
	&& token->word[len - 1] == '\'')
		return (q_single);
	if (token->word[0] == '"' \
	&& token->word[len - 1] == '"')
		return (q_double);
	return (q_not);
}

static t_list	*_init_list(char *str)
{
	t_list	*head;
	t_list	*curr;

	head = parse_quote(str);
	curr = head->next;
	free(head);
	head = curr;
	while (curr != NULL)
	{
		if (((t_token *)curr->content)->word[0] != '\0')
			((t_token *)curr->content)->type = word;
		curr = curr->next;
	}
	return (head);
}

static void	_expand_pipeline(t_list **head, t_list **curr
							, t_env *env, t_wildcard *info)
{
	t_token	*token;

	token = (*curr)->content;
	if (info->keepflag == 0)
	{
		if (info->quote != q_single && ft_strchr(token->word, '$') != NULL)
			expand_variable(token, env);
		if (info->quote != q_not)
			_remove_quote(token);
		if (info->quote == q_not)
			info->keepflag = more_split(*curr) + 1;
	}
	if (info->quote == q_not && ft_strchr(token->word, '*') != NULL)
		expand_wildcard(head, curr);
	if (info->keepflag != 0)
		info->keepflag -= 1;
}

t_list	*expand_one_word(char *str, t_env *env)
{
	t_list		*head;
	t_list		*curr;
	t_token		*token;
	t_wildcard	info;

	head = _init_list(str);
	curr = head;
	info.keepflag = 0;
	while (curr != NULL)
	{
		token = curr->content;
		if (info.keepflag == 0)
			info.quote = _is_quote(token);
		if (token->type == word)
			_expand_pipeline(&head, &curr, env, &info);
		curr = curr->next;
	}
	merge_word_nodes(&head);
	return (head);
}
