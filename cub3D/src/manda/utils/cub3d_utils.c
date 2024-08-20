/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 07:00:10 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

void	print_error(char *s)
{
	ft_putendl_fd("Error", 2);
	if (s)
		ft_putendl_fd(s, 2);
	exit(1);
}
