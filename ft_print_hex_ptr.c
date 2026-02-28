#include "ft_printf.h"

int	ft_print_str(char *s);

static int	write_char(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	puthex(unsigned long n, int uppercase)
{
	const char	*base;
	int		count;
	int		tmp;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count = puthex(n / 16, uppercase);
		if (count < 0)
			return (-1);
		tmp = puthex(n % 16, uppercase);
		if (tmp < 0)
			return (-1);
		return (count + tmp);
	}
	return (write_char(base[n]));
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	return (puthex((unsigned long)n, uppercase));
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;
	int				tmp;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	if (count < 0)
		return (-1);
	addr = (unsigned long)ptr;
	tmp = puthex(addr, 0);
	if (tmp < 0)
		return (-1);
	return (count + tmp);
}
