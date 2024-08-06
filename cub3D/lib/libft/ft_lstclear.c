/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:35:30 by taerakim          #+#    #+#             */
/*   Updated: 2024/08/01 13:25:31 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	next = tmp->next;
	while (tmp->next != NULL)
	{
		del(tmp->content);
		free(tmp);
		tmp = next;
		next = next->next;
	}
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}
