#include "ft_printf.h"

int	ft_do_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putsp("%", 1);
	count += ft_do_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putsp("%", 1);
	return (count);
}