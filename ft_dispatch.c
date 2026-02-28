#include "ft_printf.h"

int	ft_print_char(int c);
int	ft_print_percent(void);
int	ft_print_str(char *s);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_ptr(void *ptr);

int	dispatch_conversion(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	if (spec == '%')
		return (ft_print_percent());
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_print_uint(va_arg(*ap, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	return (0);
}