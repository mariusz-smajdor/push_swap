#include "../pushswap.h"

int	ft_atoi(const char *str)
{
	int		counter;
	int		sign;
	size_t	i;

	counter = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		counter = counter * 10 + (str[i] - '0');
		i++;
	}
	return (counter * sign);
}