/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:11:58 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:12:10 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_do_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putst(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input(str, num, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_do_width(flags.width, 0, 0);
	}
	else
		count += ft_do_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_input(str, num, flags);
	return (count);
}

int			ft_do_int(int i, t_flags flags)
{
	int		count;
	int		num;
	char	*str;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_do_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_putst("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_put_int(str, num, flags);
	free(str);
	return (count);
}
