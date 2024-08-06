/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:24:26 by inryu             #+#    #+#             */
/*   Updated: 2024/08/06 14:06:29 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		print_error("file with the .cub extension only");
	if (ft_strncmp(file + (len - 4), ".cub", 4))
		print_error("file with the .cub extension only");
}

void	into_d(t_list *head, t_info *info)
{
	int		i;
	int		j;
	t_list	*cur;

	info->vert--;
	info->map = ft_calloc(info->vert, sizeof(char **));
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

	check_extension(av[1]);
	arg = open(av[1], O_RDONLY);
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
	valid_map(info->map);
	int	i;
	i = 0;
	while(i < info->vert)
	{
		printf("[%s]\n", info->map[i]);
		i++;
	}
}
