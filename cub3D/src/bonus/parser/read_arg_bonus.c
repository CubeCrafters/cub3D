/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:24:26 by inryu             #+#    #+#             */
/*   Updated: 2024/08/21 16:45:40 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		print_error("file with the .cub extension only");
	if (ft_strncmp(file + (len - 4), ".cub", 4))
		print_error("file with the .cub extension only");
	return (open(file, O_RDONLY));
}

void	into_d(t_list *head, t_info *info)
{
	int		i;
	int		j;
	t_list	*cur;

	info->vert--;
	info->map = ft_calloc(info->vert + 1, sizeof(char **));
	i = 0;
	cur = head;
	while (i < info->vert)
	{
		j = 0;
		info->map[i] = ft_calloc(info->hori + 1, sizeof(char *));
		while (j < info->hori)
		{
			if (j < (int)ft_strlen(cur->content))
				info->map[i][j] = cur->content[j];
			else
				info->map[i][j] = ' ';
			j++;
		}
		cur = cur->next;
		i++;
	}
}

void	read_map(char *s, t_list **head, t_info *info)
{
	t_list	*new;
	char	*tmp;

	tmp = ft_strtrim(s, "\n");
	new = ft_lstnew(tmp);
	if (*head == NULL)
	{
		if (ft_strlen(tmp) > 0)
			*head = new;
	}
	else
		ft_lstadd_back(head, new);
	if ((int)ft_strlen(tmp) > info->hori)
		info->hori = ft_strlen(tmp);
	if (head != NULL)
		info->vert++;
}

void	read_arg(char **av, t_info *info)
{
	int		arg;
	char	*s;
	t_list	*head;
	t_check	ch;

	arg = check_extension(av[1]);
	if (arg < 0)
		print_error("File open failed");
	ft_bzero(&ch, sizeof(t_check));
	head = NULL;
	while (1)
	{
		s = get_next_line(arg);
		if (!s)
			break ;
		if (ch.no * ch.so * ch.we * ch.ea * ch.f * ch.c == 0)
			identifiers(s, info, &ch);
		else
			read_map(s, &head, info);
	}
	into_d(head, info);
	ft_lstclear(&head, del);
	close(arg);
	valid_info(info, &ch);
	gettimeofday(&info->time, NULL);
}
