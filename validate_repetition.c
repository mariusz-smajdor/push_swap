#include "pushswap.h"

int	validate_repetition(char **a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (a[i])
	{
		j = i + 1;
		while (a[j])
		{
			if (ft_atoi(a[i]) == ft_atoi(a[j]))
				return (ft_printf("Error\n") - 6);
			j++;
		}
		i++;
	}

	return (1);
}