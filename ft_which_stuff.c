/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:19:22 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:19:29 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_whats_zis(int c)
{
    return ((c == 'c') || (c == 's') || (c == 'p') || 
    (c == 'd') || (c == 'i') || (c == 'u') || 
    (c == 'x') || (c == 'X') || (c == '%'));
}

int ft_what_flag(int c)
{
    return ((c == '.') || (c == '*') || (c == '0') || 
    (c == '-') || (c == ' '));
}

int	ft_which_stuf(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_do_char(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_do_percent(flags);
	else if (c == 'p')
		count = ft_do_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_do_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_do_int(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_do_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_do_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_do_uint((unsigned int)va_arg(args, unsigned int), flags);
	return (count);
}
