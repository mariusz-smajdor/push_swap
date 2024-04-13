#include "../ftprintf.h"

static int	put_number(int *p_n, char *numbers)
{
	int	n_len;
	int	i;

	i = -1;
	while (++i, *p_n > 0)
	{
		numbers[i] = (*p_n % 10) + '0';
		*p_n /= 10;
	}
	n_len = i;
	while (--i, i >= 0)
		write(1, &numbers[i], 1);
	return (n_len);
}

int	print_number(int n)
{
	char	numbers[12];
	int		minus;
	int		*p_n;
	int		i;

	minus = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		minus = 1;
		write(1, "-", 1);
		n *= -1;
	}
	p_n = &n;
	return (put_number(p_n, numbers) + minus);
}
