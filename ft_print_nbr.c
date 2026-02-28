#include "ft_printf.h"

static int	putchar_c(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	putnbr_u(unsigned long n)
{
	int	count;
	int	tmp;

	if (n >= 10)
	{
		count = putnbr_u(n / 10);
		if (count < 0)
			return (-1);
		tmp = putnbr_u(n % 10);
		if (tmp < 0)
			return (-1);
		return (count + tmp);
	}
	return (putchar_c((char)('0' + n)));
}

int	ft_print_int(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		count = putchar_c('-');
		if (count < 0)
			return (-1);
		nb = -nb;
	}
	return (count + putnbr_u((unsigned long)nb));
}

int	ft_print_uint(unsigned int n)
{
	return (putnbr_u((unsigned long)n));
}