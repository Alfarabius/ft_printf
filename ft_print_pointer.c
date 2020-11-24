/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:10:16 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 15:28:37 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(t_spec sp, unsigned long toptr)
{
	char	*str;
	int		printed_bytes;
	int		size;

	if (!(str = ft_uitoa_base(toptr, 16)))
		return (-1);
	printed_bytes = 0;
	size = ft_strlen(str);
	if (sp.flag == '-')
	{
		ft_putbyte(&(sp.width), &printed_bytes, '0');
		ft_putbyte(&(sp.width), &printed_bytes, 'x');
		while (size--)
			ft_putbyte(&(sp.width), &printed_bytes, *(str++));
		while (sp.width > 0)
			ft_putbyte(&(sp.width), &printed_bytes, ' ');
	}
	else
	{
		while (sp.width > (size + 2))
			ft_putbyte(&(sp.width), &printed_bytes, ' ');
		ft_putbyte(&(sp.width), &printed_bytes, '0');
		ft_putbyte(&(sp.width), &printed_bytes, 'x');
		while (size--)
			ft_putbyte(&(sp.width), &printed_bytes, *(str++));
	}
	return (printed_bytes);
}
