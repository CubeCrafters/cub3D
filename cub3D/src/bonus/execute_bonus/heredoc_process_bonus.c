/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:28:18 by taerakim          #+#    #+#             */
/*   Updated: 2024/05/29 20:31:55 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "execute_bonus.h"
#include "mini_signal_bonus.h"
#include "ft_error_bonus.h"

static char	*_get_tmpfilename(int order)
{
	char	*num;
	char	*res;

	num = ft_itoa(order);
	res = ft_strjoin(TMPFILE, num);
	free(num);
	return (res);
}

static void	_input_heredoc(t_redi *redi, char *tmpfile)
{
	const int	len = ft_strlen(redi->file);
	char		*in;
	int			fd;

	fd = open(tmpfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		ft_error(error_systemcall, errno, NULL);
	while (1)
	{
		in = readline("> \033[s");
		if (in == NULL)
		{
			printf("\033[u\033[1B\033[1A");
			exit(0);
		}
		if (g_signal == SIGINT)
			do_heredoc(SIGINT);
		if (ft_strncmp(redi->file, in, len + 1) == 0)
		{
			free(in);
			exit(0);
		}
		ft_putendl_fd(in, fd);
		free(in);
	}
}

int	heredoc_process(t_redi *redi, int order)
{
	struct termios	term;
	char			*tmpfile;
	int				result;
	int				pid;

	tcgetattr(1, &term);
	tmpfile = _get_tmpfilename(order);
	pid = fork();
	if (pid == -1)
		ft_error(error_systemcall, errno, NULL);
	if (pid == 0)
	{
		set_heredoc_signal();
		_input_heredoc(redi, tmpfile);
		exit(0);
	}
	result = wait_process(pid, NULL);
	tcsetattr(1, 0, &term);
	free(redi->file);
	redi->file = tmpfile;
	if (result == 1)
		g_signal = 0;
	return (result);
}
