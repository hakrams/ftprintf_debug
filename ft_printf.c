#include "ft_printf.h"

int	dispatch_conversion(char spec, va_list *ap);

static int	write_one(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	handle_percent(const char *format, int *i, va_list *ap)
{
	int	printed;

	(*i)++;
	if (!format[*i])
	{
		(*i)--;
		return (0);
	}
	printed = dispatch_conversion(format[*i], ap);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total;
	int		printed;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	total = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			printed = handle_percent(format, &i, &ap);
		else
			printed = write_one(format[i]);
		if (printed < 0)
			return (va_end(ap), -1);
		total += printed;
		i++;
	}
	va_end(ap);
	return (total);
}
