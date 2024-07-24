/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:10:43 by sehwanii          #+#    #+#             */
/*   Updated: 2024/05/29 17:49:34 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer_bonus.h"

//tokenize를 하는 main 함수
t_list	*tokenizer(char *command)
{
	t_list	*quote_parsed_list;
	t_list	*op_parsed_list;
	t_list	*temp;

	quote_parsed_list = parse_quote(command);
	op_parsed_list = parse_op(quote_parsed_list);
	add_end_token(op_parsed_list);
	if (((t_token *)op_parsed_list->content)->type == undefined)
	{
		temp = op_parsed_list;
		op_parsed_list = op_parsed_list->next;
		ft_lstdelone(temp, (void *)free_token);
	}
	merge_word_nodes(&op_parsed_list);
	free(quote_parsed_list);
	return (op_parsed_list);
}
