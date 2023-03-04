#include "ft_printf.h"

int	ft_do_width(int width, int minus, int zero)
{
	int count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}