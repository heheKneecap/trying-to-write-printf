/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:17:38 by mshchuts          #+#    #+#             */
/*   Updated: 2023/03/08 15:17:45 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (0);
	p = str;
	while (*s)
	{
		*p++ = *s++;
	}
	*p = '\0';
	return (str);
}
