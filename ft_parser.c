/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:29:44 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 16:02:44 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_flags_handler(const char *str, char flag, t_spec *spec)
{
	spec->flag = flag;
	while (*str == '-' || *str == '0')
	{
		spec->flag = (*str == '-') ? *str : flag;
		spec->offset++;
		str++;
	}
	return (spec->offset);
}

static	int	ft_mods_handler(const char *str, int *mod, t_spec *spec)
{
	int	offset;

	offset = 0;
	*mod = ft_atoi(str);
	while (ft_isdigit(str[offset]))
		offset++;
	spec->offset += offset;
	return (offset);
}

int			ft_parser(const char *str, t_spec *spec, va_list ar)
{
	if (*str == '-' || *str == '0')
		str += ft_flags_handler(str, *str, spec);
	if (ft_isdigit(*str))
		str += ft_mods_handler(str, &(spec->width), spec);
	else if (*str == '*' && (spec->offset += 1))
	{
		spec->width = va_arg(ar, int);
		spec->flag = (spec->width < 0) ? '-' : spec->flag;
		spec->width = (spec->width < 0) ? spec->width * -1 : spec->width;
		str++;
	}
	if (*str == '.' && str++ && (spec->precision = 0) == 0)
		spec->offset++;
	if (ft_isdigit(*str))
		str += ft_mods_handler(str, &(spec->precision), spec);
	else if (*str == '*' && str++ && spec->offset++)
	{
		spec->precision = va_arg(ar, int);
		spec->precision = (spec->precision < -1) ? -1 : spec->precision;
	}
	return (ft_processor(*str, spec, ar));
}
