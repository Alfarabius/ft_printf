/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:45:18 by mrosie            #+#    #+#             */
/*   Updated: 2020/11/25 16:08:57 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./Libft/libft.h"
# include <stdio.h>

typedef	struct	s_parse
{
	char		flag;
	int			width;
	int			precision;
	int			offset;
}				t_spec;

int				ft_printf(const char *format, ...);
int				ft_parser(const char *str, t_spec *spec, va_list ar);
int				ft_processor(char type, t_spec *sp, va_list ar);
int				ft_print_char(t_spec sp, char ch);
int				ft_print_number(t_spec sp, long number,
					int base, uint8_t uppercase);
int				ft_print_pointer(t_spec sp, unsigned long toptr);
int				ft_print_string(t_spec sp, char *string);
int				ft_putbyte(int *mod, int *printed_bytes, char sym);
char			*ft_itoa_base(long n, int base, uint8_t uppercase);
char			*ft_ulitoa_base(unsigned long n, int base, uint8_t uppercase);

#endif
