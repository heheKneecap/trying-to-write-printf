/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshchuts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:43:06 by mshchuts          #+#    #+#             */
/*   Updated: 2023/02/09 17:43:16 by mshchuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *str_rev (char *str)
{
    int i;
    int len = 0;
    char c;
    if (!str)
        return 0;
    while(str[len] != '\0')
    {
        len++;
    }
    for(i = 0; i < (len/2); i++)
    {
        c = str[i];
        str [i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return str;
}


char * _itoa(int i, char *strout, int base)
{
    char *str = strout;
    int digit;
    int sign = 0;
    if (i < 0)
    {
        sign = 1;
        i *= -1;
    }
    while(i)
    {
        digit = i % base;
        *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
        i = i / base;
        str ++;
    }
    if(sign)
    {
        *str++ = '-';
    }
    *str = '\0';
    str_rev(strout);
    return strout;
}

int ft_printf(const char *str, ...)
{
    va_list vl;
    int i = 0;
    int j = 0;
    char buff[100] = {0};
    char tmp[20];
    char *str_arg;

    va_start(vl, str);
    while (str && str[i])
    {
        if(str[i] == '%')
        {
            i++;
            switch (str[i])
            {
                case 'c':
                {
                    buff[j] = (char)va_arg(vl, int);
                    j++;
                    break;
                }
                case 's':
                {
                    str_arg = va_arg( vl, char* );
                    strcpy(&buff[j], str_arg);
                    j += strlen(str_arg);
                    break;
                }
                case 'd':
                {
                    _itoa(va_arg(vl, int), tmp, 10);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'X':
                {
                    
                }
                case 'p':
                {
                    
                }
                case 'i':
                {
                    
                }
                case 'u':
                {
                    
                }
                case'%':
                {
                    
                }
            }
        }
        else
        {
            buff[j] =str[i];
            j++;
        }
        i++;
    }
    fwrite(buff, j, 1, stdout);
    va_end(vl);
    return j;
}

int main()
{
    int eh = 0;
    ft_printf("you got %%\n", eh);

    printf("should've been %%", eh);
    return 0;
}
