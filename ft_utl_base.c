/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utl_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:18:22 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:19:03 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static	char    *ft_base(unsigned long long number, int base, int count, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[count - 1] = (number % base) + 48;
		else
			str[count - 1] = (number % base) + 55;
		number /= base;
		count--;
	}
	return (str);
}

char    *ft_utl_base(unsigned long long number, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	str = 0;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		count++;
	}
	if (!(str = malloc(count + 1)))
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}
