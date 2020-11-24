/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:10:54 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/23 16:59:48 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_left(char *str, t_spec sp, int size)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (*str == '-' && (size -= 1))
		str += ft_putbyte(&(sp.width), &printed_bytes, '-');
	while (sp.precision-- > size)
		ft_putbyte(&(sp.width), &printed_bytes, '0');
	while (size--)
		str += ft_putbyte(&(sp.width), &printed_bytes, *str);
	while (sp.width > 0)
		ft_putbyte(&(sp.width), &printed_bytes, ' ');
	return (printed_bytes);
}

int	ft_print_right_no_prescision(char *str, t_spec sp, int size)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (*str == '-' && (size -= 1))
		str += ft_putbyte(&(sp.width), &printed_bytes, '-');
	while (sp.width > size)
		ft_putbyte(&(sp.width), &printed_bytes, '0');
	while (size--)
		str += ft_putbyte(&(sp.width), &printed_bytes, *str);
	return (printed_bytes);
}

int	ft_print_right_with_prescision(char *str, t_spec sp, int size)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (*str == '-')
		sp.width -= 1;
	while (sp.width > sp.precision)
		ft_putbyte(&(sp.width), &printed_bytes, ' ');
	if (*str == '-')
		str += ft_putbyte(&(size), &printed_bytes, *str);
	while (sp.precision-- > size)
		ft_putbyte(&(sp.width), &printed_bytes, '0');
	while (size--)
		str += ft_putbyte(&(sp.width), &printed_bytes, *str);
	return (printed_bytes);
}

int	ft_print_right_size(char *str, t_spec sp, int size)
{
	int	printed_bytes;

	printed_bytes = 0;
	while (sp.width > size)
		ft_putbyte(&(sp.width), &printed_bytes, ' ');
	if (*str == '-')
		str += ft_putbyte(&(size), &printed_bytes, *str);
	while (size--)
		str += ft_putbyte(&(sp.width), &printed_bytes, *str);
	return (printed_bytes);
}

int	ft_print_number(t_spec sp, long number, int base, uint8_t uppercase)
{
	char	*str;
	int		printed_bytes;
	int		size;

	printed_bytes = 0;
	if (!(str = ft_itoa_base(number, base, uppercase)))
		return (-1);
	size = ft_strlen(str);
	if (sp.precision == 0 && *str == '0')
		while (sp.width > 0)
			ft_putbyte(&(sp.width), &printed_bytes, ' ');
	else if (sp.flag == '-')
		printed_bytes = ft_print_left(str, sp, size);
	else if (sp.flag == '0' && sp.precision <= 0)
		printed_bytes = ft_print_right_no_prescision(str, sp, size);
	else if (sp.precision > size)
		printed_bytes = ft_print_right_with_prescision(str, sp, size);
	else
		printed_bytes = ft_print_right_size(str, sp, size);
	free(str);
	return (printed_bytes);
}
