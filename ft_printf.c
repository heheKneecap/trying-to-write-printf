#include "ft_printf.h"

static  t_flags ft_flag(void)
{
    t_flags flags;

    flags.width = 0;
    flags.star = 0;
    flags.type = 0;
    flags.minus = 0;
    flags.zero = 0;
    flags.dot = 1;
    return(flags);
}

static int  ft_what(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_whats_zis(str[i]) && !ft_what_flag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (ft_whats_zis(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int ft_do_stuff(const char *str, va_list args)
{
    int     i;
    int     count;
    t_flags flags;
    
    i = 0;
    count = 0;
    while (!0)
    {
        flags = ft_flag();
        if (!str[i])
            break;
        else if (str[i] != '%')
            count += ft_putchar(str[i]);
        else if (str[i] == '%' && str[i + 1])
        {
            i = ft_what(str, i++, &flags, args);
            if (ft_whats_zis(str[i]))
                count += ft_which_stuf((char)flags.type, flags, args);
            else if (str[i])
                count += ft_putchar(str[i]);
        }
        i++;
    }
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list     args;
    const char  *stri;
    int         count;

    count = 0;
    if (!(stri = ft_strdup(str)))
        return(0);
    va_start(args, str);
    count += ft_do_stuff(stri, args);
    va_end(args);
    free((char *)stri);
    return (count);
}
