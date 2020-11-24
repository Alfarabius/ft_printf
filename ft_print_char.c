/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:08:49 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 15:54:17 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_spec sp, char ch)
{
	int		printed_bytes;

	printed_bytes = 1;
	if (sp.flag == '-')
		ft_putchar_fd(ch, 1);
	while (sp.width > 1)
	{
		write(1, ((sp.flag == '0') ? "0" : " "), 1);
		sp.width--;
		printed_bytes++;
	}
	if (sp.flag != '-')
		ft_putchar_fd(ch, 1);
	return (printed_bytes);
}
