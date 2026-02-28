#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	uc;
	int				res;

	uc = (unsigned char)c;
	res = write(1, &uc, 1);
	if (res < 0)
		return (-1);
	return (1);
}

int	ft_print_percent(void)
{
	char	c;
	int		res;

	c = '%';
	res = write(1, &c, 1);
	if (res < 0)
		return (-1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}