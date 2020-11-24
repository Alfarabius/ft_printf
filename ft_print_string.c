/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:09:35 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/23 11:30:07 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbyte(int *mod, int *printed_bytes, char sym)
{
	ft_putchar_fd(sym, 1);
	*printed_bytes += 1;
	*mod -= 1;
	return (1);
}

int	ft_print_string(t_spec sp, char *string)
{
	int		printed_bytes;
	int		str_size;

	if ((printed_bytes = 0) == 0 && string == NULL)
		string = "(null)";
	str_size = ft_strlen(string);
	if (sp.precision != -1 && sp.precision < str_size)
		str_size = sp.precision;
	if (sp.flag == '-')
	{
		while (sp.precision-- && *string)
			string += ft_putbyte(&(sp.width), &printed_bytes, *string);
		while (sp.width > 0)
			ft_putbyte(&(sp.width), &printed_bytes, ' ');
	}
	else
	{
		while (sp.width > str_size)
			ft_putbyte(&(sp.width), &printed_bytes, ' ');
		while (str_size)
			string += ft_putbyte(&str_size, &printed_bytes, *string);
	}
	return (printed_bytes);
}
