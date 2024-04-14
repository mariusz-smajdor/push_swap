#include "pushswap.h"

int	validate_input(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && ft_issign(av[i][j]) && ft_isdigit(av[i][j + 1]))
				j++;
			if (!ft_isdigit(av[i][j]))
				return (ft_printf("Error\n") - 6);
			j++;
		}
		i++;
	}
	return (1);
}