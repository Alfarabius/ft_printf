/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:31:42 by mrosie            #+#    #+#             */
/*   Updated: 2020/10/31 18:06:29 by mrosie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (*s != (unsigned char)c && len--)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
