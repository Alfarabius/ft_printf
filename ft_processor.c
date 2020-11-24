/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:38:50 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 15:59:25 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor(char type, t_spec *sp, va_list ar)
{
	if (type == 'c')
		return (ft_print_char(*sp, (char)va_arg(ar, int)));
	else if (type == 's')
		return (ft_print_string(*sp, va_arg(ar, char *)));
	else if (type == 'p')
		return (ft_print_pointer(*sp, va_arg(ar, unsigned long)));
	else if (type == 'd' || type == 'i')
		return (ft_print_number(*sp, va_arg(ar, int), 10, 0));
	else if (type == 'u')
		return (ft_print_number(*sp, va_arg(ar, long), 10, 0));
	else if (type == 'x')
		return (ft_print_number(*sp, va_arg(ar, long), 16, 0));
	else if (type == 'X')
		return (ft_print_number(*sp, va_arg(ar, long), 16, 1));
	else if (type == 'o')
		return (ft_print_number(*sp, va_arg(ar, unsigned long), 8, 0));
	else if (type == '%')
		return (ft_print_char(*sp, '%'));
	return (-1);
}
