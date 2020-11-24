/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:35:17 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 16:03:29 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_struct_init(t_spec *spec)
{
	spec->flag = 0;
	spec->width = 0;
	spec->precision = -1;
	spec->offset = 0;
	spec->printed_bytes = 0;
}

static	int		ft_putbyte_l(char sym, int step, const char **str)
{
	ft_putchar_fd(sym, 1);
	*str += step;
	return (1);
}

static	int		ft_parse_format(const char *str, va_list ar)
{
	t_spec	spec;
	int		printed_bytes;

	printed_bytes = 0;
	while (*str != '\0')
	{
		while (*str != '%' && *str)
			printed_bytes += ft_putbyte_l(*str, 1, &str);
		if (*str == '%' && *(str + 1) != '%')
		{
			ft_struct_init(&spec);
			if (ft_parser(++str, &spec, ar) == -1)
				return (-1);
			str += spec.offset + 1;
			printed_bytes += spec.printed_bytes;
		}
		else if (*str && *(str + 1) == '%')
			printed_bytes += ft_putbyte_l(*str, 2, &str);
	}
	return (printed_bytes);
}

int				ft_printf(const char *format, ...)
{
	va_list argptr;
	int		printed_bytes;

	va_start(argptr, format);
	printed_bytes = ft_parse_format(format, argptr);
	va_end(argptr);
	return (printed_bytes);
}
