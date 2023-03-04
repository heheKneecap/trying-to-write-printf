#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_flags
{
	int		width;
	int		star;
	int		type;
	int		minus;
	int		zero;
	int		dot;
}	t_flags;

int 	ft_printf(const char *str, ...);
int 	ft_isdigit(int c);
int 	ft_whats_zis(int c);
int 	ft_what_flag(int c);
int		ft_which_stuff(int c, t_flags flags, va_list args);
int		ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);
int		ft_do_char(char c, t_flags flags);
int		ft_do_hex(unsigned int number, int lowercase, t_flags flags);
int		ft_do_int(int i, t_flags flags);
int		ft_do_percent(t_flags flags);
int 	ft_do_pointer(unsigned long long num, t_flags flags);
int 	ft_do_string(char *str, t_flags flags);
int 	ft_do_uint(unsigned int number, t_flags flags);
int		ft_do_width(int width, int minus, int zero);
int		ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);
int		ft_strlen(const char *s);
int		ft_putst(char *str, int smth);
char 	ft_putchar(char c);
char	*ft_strdup(const char *s);
char    *ft_utl_base(unsigned long long number, int base);
t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);


#endif
