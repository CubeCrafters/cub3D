/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:55:58 by inryu             #+#    #+#             */
/*   Updated: 2024/08/01 14:23:00 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*lastone(char **backup)
{
	char	*ret;

	ret = *backup;
	*backup = NULL;
	return (ret);
}

char	*extract(char **backup)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*backup || !(ft_strchr(*backup, '\n')))
		return (lastone(backup));
	line = ft_calloc(1, (ft_strchr(*backup, '\n') - *backup + 1 + 1));
	if (!line)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	i = -1;
	while ((*backup)[++i] != '\n')
		line[i] = (*backup)[i];
	line[i] = (*backup)[i];
	line[++i] = '\0';
	temp = *backup;
	*backup = ft_strdup(&(temp[i]));
	free(temp);
	return (line);
}

char	*read_fd(int fd, char *buf, char *backup)
{
	char	*ret;
	char	*tmp;
	int		r;

	r = 1;
	ret = backup;
	while (r > 0 && !(ft_strchr(ret, '\n')))
	{
		r = read(fd, buf, 1024);
		if (r < 0)
		{
			free(ret);
			print_error("File read failed");
			return (NULL);
		}
		buf[r] = '\0';
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(tmp);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0)
		return (NULL);
	buf = ft_calloc(1, 1024 + 1);
	if (!buf)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = read_fd(fd, buf, backup);
	free(buf);
	line = extract(&backup);
	if (line && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
