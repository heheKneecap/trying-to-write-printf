/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:13:35 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:13:50 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_do_width(flags.dot, ft_strlen(str), 0);
		count += ft_putsp(str, flags.dot);
	}
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

int ft_do_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_input(str, flags);
	if (flags.dot >= 0)
		count += ft_do_width(flags.width, flags.dot, 0);
	else
		count += ft_do_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_input(str, flags);
	return (count);
}
