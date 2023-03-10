/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:13:04 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:13:12 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_putst("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_do_width(flags.dot, ft_strlen(pointer), 1);
		count += ft_putst(pointer, flags.dot);
	}
	else
		count += ft_putst(pointer, ft_strlen(pointer));
	return (count);
}

int ft_do_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((count += ft_do_width(flags.width - 2, 0, 0))
			|| 1) && ((count += ft_putst("0x", 2)) || 1));
		else
			(((count += ft_putst("0x", 2)) || 1) &&
			((count += ft_do_width(flags.width - 2, 0, 0)) || 1));
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count += ft_input(p, flags);
	count += ft_do_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_input(p, flags);
	free(p);
	return (count);
}
