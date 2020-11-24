/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:07:00 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/05 12:18:38 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(int c)
{
	return ((c == 32 || (c >= 9 && c <= 13)) ? c : 0);
}

int			ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	else if (result > 9223372036854775807)
		return (-1);
	return ((int)result * sign);
}
