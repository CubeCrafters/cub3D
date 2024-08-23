/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:04:20 by taerakim          #+#    #+#             */
/*   Updated: 2024/08/23 14:42:12 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			idx;

	result = 0;
	sign = 1;
	idx = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
		sign = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	else if (!('0' <= str[idx] && str[idx] <= '9'))
		sign = 0;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result = result * 10 + (str[idx] - '0');
		idx++;
	}
	return (result * sign);
}
