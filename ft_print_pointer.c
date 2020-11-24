/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:10:16 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/24 18:46:43 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_left(t_spec sp, char *str, int size)
{
	int printed_bytes;

	printed_bytes = 0;
	ft_putbyte(&(sp.width), &printed_bytes, '0');
	ft_putbyte(&(sp.width), &printed_bytes, 'x');
	while (size--)
		ft_putbyte(&(sp.width), &printed_bytes, *(str++));
	while (sp.width > 0)
		ft_putbyte(&(sp.width), &printed_bytes, ' ');
	return (printed_bytes);
}

static	int	ft_print_right(t_spec sp, char *str, int size)
{
	int printed_bytes;

	printed_bytes = 0;
	while (sp.width > (size + 2))
		ft_putbyte(&(sp.width), &printed_bytes, ' ');
	ft_putbyte(&(sp.width), &printed_bytes, '0');
	ft_putbyte(&(sp.width), &printed_bytes, 'x');
	while (size--)
		ft_putbyte(&(sp.width), &printed_bytes, *(str++));
	return (printed_bytes);
}

int			ft_print_pointer(t_spec sp, unsigned long toptr)
{
	char	*str;
	char	*tmp;
	int		printed_bytes;
	int		size;

	if (!(str = ft_ulitoa_base(toptr, 16, 0)))
		return (-1);
	printed_bytes = 0;
	tmp = str;
	size = ft_strlen(str);
	if (sp.flag == '-')
		ft_print_left(sp, str, size);
	else
		ft_print_right(sp, str, size);
	free(tmp);
	return (printed_bytes);
}
